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
    vector<TreeNode*> allPossibleFBT(int n) {
        // BT only exist when nodes are in even
        vector<TreeNode*> result;
        if (n == 1) {
            result.push_back(new TreeNode());
            return result;
        }

        if (n % 2 == 0) return result; // even number of BT DNE
// We will find leftSubtrees(odd) & rightSubtrees(odd) so odd+odd+1 i.e. odd

// Considering  every POSSSIBLE  node as  root
        for (int i = 1; i < n; i += 2) { 
        vector<TreeNode*> leftSubtrees = allPossibleFBT(i);
        vector<TreeNode*> rightSubtrees = allPossibleFBT(n - i - 1);

        for (int j = 0; j < leftSubtrees.size(); j++) {
            for (int k = 0; k < rightSubtrees.size(); k++) {
                TreeNode* root = new TreeNode();
                root->left = leftSubtrees[j];
                root->right = rightSubtrees[k];
                result.push_back(root);
                }
            }
        }
        return result;
    }
};