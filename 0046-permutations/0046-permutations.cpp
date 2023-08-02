class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        helper(curr, nums);
        return result;
    }
    
    void helper(vector<int>& curr, vector<int>& nums) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        
        for (int num : nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                helper(curr, nums);
                curr.pop_back();
            }
        }
    }
};
