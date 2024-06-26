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

 #pragma GCC optimize("03")
static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<TreeNode*> v;
    TreeNode* solve(int i,int j)
    {
        if(i>j) return NULL;
        int m=(i+j)/2;
        v[m]->right=solve(m+1,j);
        v[m]->left=solve(i,m-1);
        return v[m];
    }
    void Fill(TreeNode* root)
    {
        if(!root) return;
        Fill(root->left);
        v.push_back(root);
        Fill(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        Fill(root);
        return solve(0,v.size()-1);
    }
};