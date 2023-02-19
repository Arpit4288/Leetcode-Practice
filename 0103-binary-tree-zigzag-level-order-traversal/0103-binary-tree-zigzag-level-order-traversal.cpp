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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool flag = false;
        while(!q.empty()){
            vector<int> arr;
            while(q.front() != NULL){
                TreeNode* curr = q.front();
                arr.emplace_back(curr->val);
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            // for(auto it : arr) cout<<it<<" ";
            // cout<<endl;
            if(flag){
                reverse(arr.begin(), arr.end());
            }
            flag = !flag;
            ans.emplace_back(arr);
            q.pop();
            q.push(NULL);
            if(q.front() == NULL) break;
        }
        return ans;
        
    }
};