class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool right = true, left = true;
        for(int i = 1;i<nums.size(); i++){
            right = right &&  nums[i] >= nums[i-1];
            left = left && nums[i-1] >= nums[i];
        }
        
        return right || left;
    }
};