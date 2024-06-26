class Solution {
    void parentp(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            mp[root->left] = root;
            parentp(root->left, mp);
        }
        if (root->right != NULL) {
            mp[root->right] = root;
            parentp(root->right, mp); // Corrected this line
        }
        return;
    }

    void findnode(TreeNode* root, int start, TreeNode*& x) {
        if (root == NULL) {
            return;
        }
        if (root->val == start) {
            x = root;
            return;
        }
        findnode(root->left, start, x);
        findnode(root->right, start, x);
    }

    void dfs(TreeNode* x, map<TreeNode*, TreeNode*>& mp, set<TreeNode*>& vis, int min, int& result) {
        if (x == NULL) {
            result = max(result, min - 1);
            return;
        }
        if (vis.find(x) != vis.end()) {
            return;
        }
        vis.insert(x);
        dfs(x->left, mp, vis, min + 1, result);
        dfs(x->right, mp, vis, min + 1, result);
        dfs(mp[x], mp, vis, min + 1, result);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mp; // to store the parent
        parentp(root, mp);
        TreeNode* x = NULL;
        findnode(root, start, x);
        set<TreeNode*> vis;
        int result = 0;
        dfs(x, mp, vis, 0, result);
        return result;
    }
}; 