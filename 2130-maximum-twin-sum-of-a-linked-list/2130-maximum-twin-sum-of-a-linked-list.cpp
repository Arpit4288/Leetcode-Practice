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
    int pairSum(ListNode* head) {
        int maxSum = INT_MIN;
        
        // Calculate the length of the linked list
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            length++;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        int mid = length / 2;
        
        // Move the 'fast' pointer to the middle of the linked list
        for (int i = 0; i < mid; i++) {
            fast = fast->next;
        }
        
        // Reverse the second half of the linked list
        ListNode* prev = nullptr;
        while (fast != nullptr) {
            ListNode* next = fast->next;
            fast->next = prev;
            prev = fast;
            fast = next;
        }
        
        // Traverse both halves of the linked list and calculate the twin sums
        fast = prev; // 'fast' now points to the reversed second half
        while (slow != nullptr && fast != nullptr) {
            int sum = slow->val + fast->val;
            maxSum = max(maxSum, sum);
            slow = slow->next;
            fast = fast->next;
        }
        
        return maxSum;
    }
};