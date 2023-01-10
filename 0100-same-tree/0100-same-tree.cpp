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
    
    bool dfs(TreeNode *root1, TreeNode *root2){
        if(!root1 && !root2) return true;  // if both root becomes empty
        if(!root1 && root2) return false;  // if root1 empty but root2 not then return false
        if(root1 && !root2) return false;  // if root2 empty but root1 not then return false
        if(root1->val != root2->val) return false;  // if both are not empty but values are not matched
        return dfs(root1->left, root2->left) && dfs(root1->right, root2->right); // if all fine then check for next left and right as well
    }
    
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);  // dfs calling
    }
};