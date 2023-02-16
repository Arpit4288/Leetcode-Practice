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
    
    int dfs(TreeNode* root, int currDepth){
        if(!root) return currDepth;
        currDepth++;
        return max(dfs(root->left, currDepth), dfs(root->right, currDepth));
    }
    
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};