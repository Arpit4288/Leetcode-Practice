class Solution {
public:
    void help(TreeNode*root,int& ans,string & s){
        if(!root) return;
        s[root->val-1]=s[root->val-1]=='0'?'1':'0';
        if(!root->left && !root->right) if(count(s.begin(),s.end(),'1')<2) ans++;
        help(root->left,ans,s);
        help(root->right,ans,s);
        s[root->val-1]=s[root->val-1]=='0'?'1':'0';
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        string s="000000000";
        help(root,ans,s);
        return ans;
    }
};