class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int i = 0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while(cur != NULL){
            if(s.find(cur->val) != s.end()){
                prev->next = cur->next;
                delete cur;
            }
            else{
                prev = cur;
            }
            cur = prev->next;
        }

        return dummy.next;
    }
};