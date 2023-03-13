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

class cmp{
public:
    bool operator() (ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp > q;
        for(auto it : lists){
            if(it != NULL) q.push(it);
        }
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        while(!q.empty()){
            ListNode* tempNode = q.top();
            curr->next = tempNode;
            curr = curr->next;
            if(tempNode->next) q.push(tempNode->next);
            q.pop();
        }
        return head->next;
    }
};