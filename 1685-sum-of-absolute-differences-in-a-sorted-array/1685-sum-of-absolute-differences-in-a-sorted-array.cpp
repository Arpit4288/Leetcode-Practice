class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        vector<int> preSum(n, 0);

        preSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            preSum[i] = preSum[i - 1] + nums[i];

        for (int i = 0; i < n; i++) {
            int leftSum = i * nums[i] - (i > 0 ? preSum[i - 1] : 0);
            int rightSum = (preSum[n - 1] - preSum[i]) - (n - 1 - i) * nums[i];

            nums[i] = leftSum + rightSum;
        }

        return nums;
    }
};