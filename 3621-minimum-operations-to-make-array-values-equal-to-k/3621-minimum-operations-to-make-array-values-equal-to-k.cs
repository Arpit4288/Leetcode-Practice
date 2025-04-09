public class Solution {
    public int MinOperations(int[] nums, int k) => !nums.Any(x => x < k)
        ? nums.Distinct().Count(m => m > k)
        : -1;
}