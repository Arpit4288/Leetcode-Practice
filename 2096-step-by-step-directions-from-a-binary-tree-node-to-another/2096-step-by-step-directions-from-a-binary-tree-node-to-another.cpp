/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x, left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||root==p||root==q) {
            return root;
        }
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(left!=nullptr&&right!=nullptr) {
            return root;
        }
        return left!=nullptr?left:right;
    }
    
    int findLevel(TreeNode* root, int value, int level) {
        if(root==nullptr) return -1;
        if(root->val==value) return level;
        
        int left=findLevel(root->left,value,level+1);
        if(left==-1) return findLevel(root->right,value,level+1);
        
        return left;
    }
    
    bool chk(TreeNode* node, int target, string& path) {
        if(node==nullptr) {
            return false;
        }
        if(node->val==target) {
            return true;
        }
        if(node->left&&chk(node->left,target,path)) {
            path.push_back('L');
            return true;
        }
        if(node->right&&chk(node->right,target,path)) {
            path.push_back('R');
            return true;
        }
        return false;
    }
    
    string getPath(TreeNode* root, int target) {
        string path;
        if(chk(root,target,path)) {
            reverse(path.begin(), path.end());
            return path;
        }
        return "";
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* startNode=nullptr;
        TreeNode* destNode=nullptr;
        
        
        function<void(TreeNode*)> findNodes=[&](TreeNode* node) {
            if(node==nullptr) return;
            if(node->val==startValue) startNode=node;
            if(node->val==destValue) destNode=node;
            findNodes(node->left);
            findNodes(node->right);
        };
        
        findNodes(root);
        
        TreeNode* newroot=lca(root, startNode, destNode);
        
        int startLevel=findLevel(newroot, startValue, 0);
        
        string ans(startLevel, 'U');
        string res=getPath(newroot, destValue);
        ans+=res;
        
        return ans;
    }
};