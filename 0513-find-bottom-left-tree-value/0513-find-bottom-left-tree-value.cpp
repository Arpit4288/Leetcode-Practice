class Solution {
    int hmax = -1, ans = 0;
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(level>hmax) hmax=level, ans=root->val;
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};