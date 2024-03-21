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

// Recursive method
class Solution {
public:
    ListNode* reverse(ListNode *curr, ListNode *prev){
        if(!curr) return prev;
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        prev = reverse(curr,prev);
        return prev;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prev = NULL;
        return reverse(head,prev);
    }
};


// Iterative method 

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(!head || !head->next) return head;
//         ListNode *curr = head, *prev = NULL;
//         while(curr){
//             ListNode *temp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = temp;
//         }
//         return prev;
        
//     }
// };