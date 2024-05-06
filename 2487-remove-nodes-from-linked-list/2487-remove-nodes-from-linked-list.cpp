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
    
    ListNode* solve(ListNode *head){
        // calling base function
        ListNode* nexti = removeNodes(head->next);
        if(nexti->val > head->val) {
            return nexti;
        }
        head->next = nexti;
        return head;
    }
    
    
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return head;
        return solve(head);
    }
};