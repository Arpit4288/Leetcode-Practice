public class Solution {
    public int MaximumDifference(int[] nums) => nums.
        Aggregate((min: int.MaxValue, max: -1), (curr, num) =>
            (
                min: Math.Min(curr.min, num), 
                current: curr.min < num ? Math.Max(num - curr.min, curr.max) : curr.max
            ),
            curr => curr.max);            
}