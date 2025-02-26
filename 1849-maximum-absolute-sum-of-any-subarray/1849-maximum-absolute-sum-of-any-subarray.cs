public class Solution {
    public int MaxAbsoluteSum(int[] nums) {
        var maxSum = 0;
        var minDiffrence = 0;
        var currentSum = 0;
        var currentDiffrence = 0;
        foreach (var num in nums) {
            currentSum += num;
            currentDiffrence += num;
            maxSum = Math.Max(currentSum, maxSum);
            minDiffrence = Math.Min(currentDiffrence, minDiffrence);
            currentSum = Math.Max(currentSum, 0);
            currentDiffrence = Math.Min(currentDiffrence, 0);
        }

        return Math.Max(maxSum, -minDiffrence);
    }
}