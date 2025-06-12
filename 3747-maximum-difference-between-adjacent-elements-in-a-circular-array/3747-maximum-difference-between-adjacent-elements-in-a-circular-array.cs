public class Solution {
    public int MaxAdjacentDistance(int[] nums) {
        int maxDiff = 0;
        int n = nums.Length;

        for (int i = 0; i < n; i++) {
            int nextIndex = (i + 1) % n; // Circular wrap-around
            int diff = Math.Abs(nums[i] - nums[nextIndex]);
            maxDiff = Math.Max(maxDiff, diff);
        }

        return maxDiff;
    }
}