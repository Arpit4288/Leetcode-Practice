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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode *currf = head;
        ListNode *currb = head;
        for(int i = 0;i<n;i++){
            currf = currf->next;
        }
        if(currf == NULL){
            head = head->next;
            return head;
        }
        while(currf->next){
            currf = currf->next;
            currb = currb->next;
        }
        currb->next = currb->next->next;
        return head;
    }
};