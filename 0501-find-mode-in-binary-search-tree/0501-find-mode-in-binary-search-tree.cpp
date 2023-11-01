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
    map<int, int> mp; // To store the frequency
    void inorder(TreeNode* root){
        // Simple inorder traversal 
        if(root==NULL)
        return;

        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {

        vector<int> ans;

        inorder(root);

        int maxi=0;
        // finding the maximum frequency 
        for(auto it: mp){
            if(it.second>maxi)
            maxi=it.second;
        }

        for(auto it: mp){
            if(it.second==maxi)
            ans.push_back(it.first);
        }

        return ans;
    }
};