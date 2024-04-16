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
    int finddepth(TreeNode *root){
        int cnt = 0;
        queue<TreeNode*> qu;
        qu.push(root);
        qu.push(NULL);
        cnt++;
        while(!qu.empty()){
            TreeNode *curr;
            while(qu.front() != NULL){
                curr = qu.front();
                qu.pop();
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            qu.pop();
            if(qu.empty() == true) return cnt;
            else{
                cnt++;
                qu.push(NULL);
            }
        }
        return cnt;
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // cout<<finddepth(root)<<endl;
        // int dep = finddepth(root);
        queue<TreeNode*> qu;
        TreeNode *curr = root;
        qu.push(root);
        qu.push(NULL);
        int cnt = 1;
        int flag = 0;
        while(!qu.empty()){
            if(depth == 1){
                TreeNode *temp = new TreeNode(val);
                temp->left = root;
                return temp;
            }
            else if(cnt == depth-1){
                TreeNode *temp;
                while(qu.front() != NULL){
                    temp = qu.front();
                    qu.pop();
                        TreeNode *temp2 = new TreeNode(val);
                        TreeNode *lef = temp->left;
                        temp->left = temp2;
                        temp2->left = lef;
                        TreeNode *temp3 = new TreeNode(val);
                        TreeNode *rig = temp->right;
                        temp->right = temp3;
                        temp3->right = rig;
                }
                break;
            }
            else{
                TreeNode *temp;
                while(qu.front() != NULL){
                    temp = qu.front();
                    qu.pop();
                    if(temp->left) qu.push(temp->left);
                    if(temp->right) qu.push(temp->right);
                }
                qu.pop();
                if(!qu.empty()) qu.push(NULL);
                cnt++;
            }
        }
        return root;
    }
};