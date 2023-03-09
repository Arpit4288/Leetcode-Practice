/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *slow = head, *fast = head;
        do{
            if(slow->next == NULL || fast->next == NULL || fast->next->next == NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        slow = head;
        while(slow != fast){
            if(slow->next == NULL || fast->next == NULL || fast->next->next == NULL) return NULL;
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};