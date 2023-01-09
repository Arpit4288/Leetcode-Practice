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
    
    void preOrder(TreeNode *root, vector<int> &ans){
        if(!root) return;  // if rooot becomes null
        ans.emplace_back(root->val);  // storing the root in the ans
        preOrder(root->left, ans);  // calling left half of tree
        preOrder(root->right, ans);  // calling right half of the tree
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
};