class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> subs = {0};
        vector<bool> res;
        int counter = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i-1] % 2) counter++;
            subs.push_back(counter);
        }

        for (auto q : queries)
            res.push_back(subs[q[0]] == subs[q[1]]);

        return res;
    }
};