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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool inpath(ListNode* head, TreeNode* root)
    {
        if(root==NULL && head!=NULL)
            return false;
    
        if(head==NULL)
            return true;
    
        if(head->val!=root->val)
            return false;
        
        // if(root->left && head->next && root->left->val == head->next->val)
        bool b1=inpath(head->next,root->left);
        
        //if(root->right && head->next && root->right->val == head->next->val)
        bool b2=inpath(head->next,root->right);
    
        return b1||b2;
    
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {        
        
        if(root==NULL)
            return false;
    
        if(root->val == head->val)
        {
            if(inpath(head,root))
                return true;
        }
    
        bool b1=isSubPath(head,root->left);
        bool b2=isSubPath(head,root->right);
    
        return b1 || b2;
        
    }
};