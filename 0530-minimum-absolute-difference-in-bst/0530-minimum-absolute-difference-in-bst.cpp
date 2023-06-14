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
    void findMin(TreeNode* root, priority_queue<int> &pq){
        if(!root) return;
        pq.push(root->val);
        findMin(root->left, pq);
        findMin(root->right, pq);
    }
    int getMinimumDifference(TreeNode* root) {
        priority_queue<int> pq;
        findMin(root, pq);
        int ans = INT_MAX;
        int prev = pq.top();
        pq.pop();
        while(!pq.empty()){
            ans = min(ans, abs(prev - pq.top()));
            prev = pq.top();
            pq.pop();
        }
        return ans;
    }
};