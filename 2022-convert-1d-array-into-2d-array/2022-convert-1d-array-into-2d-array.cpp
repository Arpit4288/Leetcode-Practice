class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        int c = 0;
        if (m * n != original.size()) {
            return {};
        }
        vector<int> res;
        for (int i = 0; i < original.size(); i++) {
            res.push_back(original[i]);
            c++;
            if (c == n) {
                ans.push_back(res);
                res.clear();
                c = 0;
            }
        }
        return ans;
    }
};