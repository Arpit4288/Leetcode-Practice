class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        while(nums.back() > n) nums.pop_back();
        long long sum = 0;
        int ans = 0;
        for(int num: nums) {
            while(sum+1 < num) sum += sum+1, ans++;
            sum += num;
        }
        while(sum < n) sum += sum+1, ans++;
        return ans;
    }
};