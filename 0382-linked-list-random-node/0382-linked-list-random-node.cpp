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
    int Len = 0;
    ListNode* HeadNode;
public:
    Solution(ListNode* head) {
        HeadNode = head;
        ListNode* curr = head;
        while(curr){
            Len++;
            curr = curr->next;
        }
    }
    
    int getRandom() {
        int randIdx = rand()%Len;
        ListNode *curr = HeadNode;
        while(randIdx--){
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */