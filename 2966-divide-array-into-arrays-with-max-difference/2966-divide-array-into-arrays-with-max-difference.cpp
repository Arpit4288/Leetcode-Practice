class Solution {
public:
    // time/space: O(nlogn)/O(logn)
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // sort the array
        sort(nums.begin(), nums.end());

        // check the condition
        for (int i = 0; i < nums.size(); i += 3) {
            if ((nums[i + 2] - nums[i]) > k) return vector<vector<int>>();
        }

        // divide the array into arrays of size `3`
        vector<vector<int>> arrays;
        for (int i = 0; i < nums.size(); i += 3) {
            arrays.push_back({});
            for (int j = 0; j < 3; j++) arrays.back().push_back(nums[i + j]);
        }
        return arrays;
    }
};