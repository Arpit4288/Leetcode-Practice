public class Solution {
    public int MaximumCount(int[] nums) {
        var posCount = nums.Count(x => x < 0);
        var negCount = nums.Count(x => x > 0);
        return posCount > negCount ? posCount : negCount;
    }
}