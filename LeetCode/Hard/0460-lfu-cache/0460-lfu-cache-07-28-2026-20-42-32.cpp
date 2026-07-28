class LFUCache {
public:

    //-----------------------------------------------------
    // Node of the doubly linked list
    //-----------------------------------------------------
    class Node {
    public:
        int key;
        int value;
        int freq;

        Node *prev;
        Node *next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;          // Every new node starts with frequency 1
            prev = nullptr;
            next = nullptr;
        }
    };

    //-----------------------------------------------------
    // Doubly Linked List
    // Each frequency owns one DLL
    //-----------------------------------------------------
    class List {
    public:
        Node *head;
        Node *tail;
        int size;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        //-------------------------------------------------
        // Insert node right after head
        // (Most Recently Used in this frequency)
        //-------------------------------------------------
        void addFront(Node *node) {

            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            size++;
        }

        //-------------------------------------------------
        // Remove node from this list
        //-------------------------------------------------
        void remove(Node *node) {

            node->prev->next = node->next;
            node->next->prev = node->prev;

            size--;
        }

        //-------------------------------------------------
        // Remove Least Recently Used node
        // (node before dummy tail)
        //-------------------------------------------------
        Node* removeLast() {

            if(size == 0)
                return nullptr;

            Node* node = tail->prev;

            remove(node);

            return node;
        }
    };

    //-----------------------------------------------------
    // Cache variables
    //-----------------------------------------------------
    int capacity;
    int minFreq;

    // key -> node
    unordered_map<int, Node*> keyMap;

    // frequency -> linked list
    unordered_map<int, List*> freqMap;

    //-----------------------------------------------------
    // Constructor
    //-----------------------------------------------------
    LFUCache(int capacity) {

        this->capacity = capacity;
        minFreq = 0;
    }

    //-----------------------------------------------------
    // Increase frequency of a node
    //-----------------------------------------------------
    void updateFrequency(Node *node) {

        int oldFreq = node->freq;

        // Remove node from old frequency list
        freqMap[oldFreq]->remove(node);

        //-------------------------------------------------
        // If old frequency became empty
        // and it was minimum frequency,
        // increase minFreq
        //-------------------------------------------------
        if(oldFreq == minFreq &&
           freqMap[oldFreq]->size == 0)
        {
            minFreq++;
        }

        // Increase node frequency
        node->freq++;

        //-------------------------------------------------
        // Create new list if needed
        //-------------------------------------------------
        if(freqMap.find(node->freq) == freqMap.end())
            freqMap[node->freq] = new List();

        // Insert node into new frequency list
        freqMap[node->freq]->addFront(node);
    }

    //-----------------------------------------------------
    // GET
    //-----------------------------------------------------
    int get(int key) {

        // Key not present
        if(keyMap.find(key) == keyMap.end())
            return -1;

        Node* node = keyMap[key];

        // Increase frequency
        updateFrequency(node);

        return node->value;
    }

    //-----------------------------------------------------
    // PUT
    //-----------------------------------------------------
    void put(int key, int value) {

        //-------------------------------------------------
        // Capacity = 0
        //-------------------------------------------------
        if(capacity == 0)
            return;

        //-------------------------------------------------
        // Key already exists
        //-------------------------------------------------
        if(keyMap.find(key) != keyMap.end()) {

            Node* node = keyMap[key];

            // Update value
            node->value = value;

            // Treat update as an access
            updateFrequency(node);

            return;
        }

        //-------------------------------------------------
        // Cache Full
        //-------------------------------------------------
        if(keyMap.size() == capacity) {

            // Remove LRU node
            // from minimum frequency list
            Node* victim =
                freqMap[minFreq]->removeLast();

            keyMap.erase(victim->key);

            delete victim;
        }

        //-------------------------------------------------
        // Insert new node
        //-------------------------------------------------
        Node* node = new Node(key, value);

        // New node always has frequency = 1
        minFreq = 1;

        if(freqMap.find(1) == freqMap.end())
            freqMap[1] = new List();

        freqMap[1]->addFront(node);

        keyMap[key] = node;
    }
};