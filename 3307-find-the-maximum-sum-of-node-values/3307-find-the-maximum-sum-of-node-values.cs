public class Solution {
    public long MaximumValueSum(int[] nums, int k, int[][] edges) {
        int n = nums.Length;
        long[,] dp = new long[n + 1, 2];
        
        // Base case initialization
        dp[n, 1] = 0;
        dp[n, 0] = long.MinValue;
        
        // Iterate through the nums array in reverse order
        for (int index = n - 1; index >= 0; index--) {
            for (int isEven = 0; isEven <= 1; isEven++) {
                long dontPerformOperation = dp[index + 1, isEven] + nums[index];
                long performOperation = dp[index + 1, isEven ^ 1] + (nums[index] ^ k);
                
                dp[index, isEven] = Math.Max(dontPerformOperation, performOperation);
            }
        }
        
        // The result is the maximum sum starting with an even number of operations
        return dp[0, 1];
    }
}