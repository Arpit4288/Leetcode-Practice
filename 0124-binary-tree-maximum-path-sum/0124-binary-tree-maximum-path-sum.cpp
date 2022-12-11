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
    int maxAns = INT_MIN;
    
    int dfs(TreeNode* root, int sum){
        if(!root) return sum;
        int curr = 0, leftSum = 0, rightSum = 0;
        leftSum += dfs(root->left, sum);
        rightSum += dfs(root->right, sum);
        curr = root->val;
        int tempPath = curr;
        if(leftSum > 0) tempPath += leftSum;
        if(rightSum > 0) tempPath += rightSum;
        maxAns = max(maxAns, tempPath);
        int maxi = max(leftSum, rightSum);
        if(maxi > 0){
            curr = curr+maxi;
        }
        
        return curr;
    }
    
    
    int maxPathSum(TreeNode* root) {
        int ans = dfs(root, 0);
        return maxAns;
    }
};