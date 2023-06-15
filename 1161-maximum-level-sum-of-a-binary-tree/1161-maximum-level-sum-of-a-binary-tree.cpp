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
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.push(root);
        int maxSum = root->val;
        int ans = 1;
        int level = 1;
        while (!queue.empty()) {
            int levelSize = queue.size();
            int levelSum = 0;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* removed = queue.front();
                queue.pop();
                levelSum += removed->val;
                if (removed->left != nullptr) queue.push(removed->left);
                if (removed->right != nullptr) queue.push(removed->right);
            }
            if (levelSum > maxSum) {
                maxSum = levelSum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};