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
    vector<int> arr;
    vector<int> arr2;
    void inorder(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right){
            arr.emplace_back(root->val);
        }
        inorder(root->left);
        inorder(root->right);
    }
    void inorder2(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right){
            arr2.emplace_back(root->val);
        }
        inorder2(root->left);
        inorder2(root->right);
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        inorder2(root2);
        // for(auto it : arr) cout<<it<<"  ";
        // cout<<endl;
        // for(auto it : arr2) cout<<it<<"  ";
        // cout<<endl;
        if(arr.size() != arr2.size()) return false;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] != arr2[i]) return false;
        }
        return true;
    }
};