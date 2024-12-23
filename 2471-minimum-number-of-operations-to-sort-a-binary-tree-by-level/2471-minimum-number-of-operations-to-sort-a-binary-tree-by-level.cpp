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
    
    int minSwaps(vector<int> arr, int len){
    map<int, int> map;
    for (int i = 0; i < len; i++)
        map[arr[i]] = i;
 
    sort(arr.begin(), arr.end());
 
    // To keep track of visited elements. Initialize
    // all elements as not visited or false.
    vector<bool> visited(len, 0);
 
    // Initialize result
    int ans = 0;
    for (int i = 0; i < len; i++) {
 
        // already swapped and corrected or
        // already present at correct pos
        if (visited[i] || map[arr[i]] == i)
            continue;
 
        int j = i, cycle_size = 0;
        while (!visited[j]) {
            visited[j] = true;
 
            // move to next node
            j = map[arr[j]];
            cycle_size++;
        }
 
        // Update answer by adding current cycle.
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}
    
    int minimumOperations(TreeNode* root) {
       int ans = 0;
        if(!root) return ans;
        TreeNode *curr = root;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            vector<int> temp;
            TreeNode *curr;
            while(q.front() != NULL){
                curr = q.front();
                temp.emplace_back(curr->val);
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans += minSwaps(temp, temp.size());
            q.pop();
            q.push(NULL);
            if(q.front() == NULL) break;
        }
        return ans;
    }
};
