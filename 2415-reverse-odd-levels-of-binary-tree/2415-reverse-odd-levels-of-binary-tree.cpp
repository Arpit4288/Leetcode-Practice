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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int x = 0,n;
        vector<TreeNode*> v;
        TreeNode* p;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){//level order traversal 
            n = q.size();
            while(n--){
                p = q.front();
                q.pop();
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
                if(x&1){
                    v.push_back(p);
                }
            }
            for(int i = 0; i < v.size()/2; i++){
                swap(v[i]->val,v[v.size()-1-i]->val);//if odd level reverse val or node->val
            }
            v.clear();
            x++;
        }
        return root;
    }
};