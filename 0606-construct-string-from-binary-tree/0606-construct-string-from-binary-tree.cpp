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
    string func(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        string result = to_string(root->val);

        string left = func(root->left);
        string right = func(root->right);

        if (!left.empty() || !right.empty()) {
            result += "(" + left + ")";
        }

        if (!right.empty()) {
            result += "(" + right + ")";
        }

        return result;
    }
        
    string tree2str(TreeNode* root) {
        return func(root);
    }
};