class LRUCache {
public:
    // -----------------------------
    // Node of the Doubly Linked List
    // -----------------------------
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    // HashMap:
    // key -> address of the node in linked list
    unordered_map<int, Node*> mp;

    // Dummy head and dummy tail
    // They simplify insertion/deletion.
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        // Create dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        // Initially
        // head <-> tail
        head->next = tail;
        tail->prev = head;
    }

    //--------------------------------------------------
    // Insert a node immediately after head.
    // This makes it the Most Recently Used (MRU).
    //--------------------------------------------------
    void insertFront(Node* node) {

        // Existing first real node
        Node* first = head->next;

        // Connect head -> node
        head->next = node;
        node->prev = head;

        // Connect node -> first
        node->next = first;
        first->prev = node;
    }

    //--------------------------------------------------
    // Remove any node from the linked list.
    //--------------------------------------------------
    void removeNode(Node* node) {

        Node* left = node->prev;
        Node* right = node->next;

        // Skip over node
        left->next = right;
        right->prev = left;
    }

    //--------------------------------------------------
    // GET operation
    //--------------------------------------------------
    int get(int key) {

        // Key not found
        if (mp.find(key) == mp.end())
            return -1;

        // Get pointer to the node
        Node* node = mp[key];

        // Since we accessed it,
        // move it to the front.
        removeNode(node);
        insertFront(node);

        return node->value;
    }

    //--------------------------------------------------
    // PUT operation
    //--------------------------------------------------
    void put(int key, int value) {

        //--------------------------------------------------
        // Case 1:
        // Key already exists.
        //--------------------------------------------------
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Update value
            node->value = value;

            // Move to front because it's recently used
            removeNode(node);
            insertFront(node);

            return;
        }

        //--------------------------------------------------
        // Case 2:
        // New key
        //--------------------------------------------------

        // If cache is full
        if (mp.size() == capacity) {

            // Least Recently Used node
            // is just before dummy tail
            Node* lru = tail->prev;

            // Remove from linked list
            removeNode(lru);

            // Remove from hashmap
            mp.erase(lru->key);

            // Free memory
            delete lru;
        }

        // Create new node
        Node* node = new Node(key, value);

        // Insert at front
        insertFront(node);

        // Store in hashmap
        mp[key] = node;
    }
};