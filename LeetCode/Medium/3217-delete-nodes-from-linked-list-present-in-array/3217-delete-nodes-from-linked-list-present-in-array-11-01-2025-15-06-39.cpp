class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> check;
        for(int num:nums) check[num]++;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        while(current->next){
            if(check[current->next->val]){
                ListNode* NodeToDelete = current->next;
                current->next = current->next->next;
                delete NodeToDelete;
            }
            else current = current->next;
        }
        return dummy->next;
    }
};