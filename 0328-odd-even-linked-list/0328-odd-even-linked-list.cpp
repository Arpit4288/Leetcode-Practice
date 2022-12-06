/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<ListNode*> arr;
        ListNode *curr = head;
        // arr.emplace_back(curr);
        while(curr){
            arr.emplace_back(curr);
            curr = curr->next;
        }
        curr = head;
        ListNode *ans = curr;
        for(int i = 1 ;i<arr.size();i++){
            if((i+1)%2 != 0){
                ListNode *temp = new ListNode(arr[i]->val);
                curr->next = temp;
                curr = curr->next;
            }
        }
        for(int i = 1 ;i<arr.size();i++){
            if((i+1)%2 == 0){
                ListNode *temp = new ListNode(arr[i]->val);
                curr->next = temp;
                curr = curr->next;
            }
        }
        return ans;
    }
};