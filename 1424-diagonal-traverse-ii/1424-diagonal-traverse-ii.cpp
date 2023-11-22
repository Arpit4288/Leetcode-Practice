class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = 0;
        for (auto& x: nums) n = max(n, (int) x.size());
        
        vector<vector<int>> bucket (m+n-1);
        for (int i = m-1; i >= 0; i-=1) {
            for (int j = 0; j < nums[i].size(); j+=1)
                bucket[i+j].emplace_back(nums[i][j]);
        }
        
        vector<int> ans;
        for (auto& x: bucket) {
            for (int& y: x) ans.emplace_back(y);
        }
        return ans;
    }
};