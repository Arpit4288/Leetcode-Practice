public class Solution {
    public long CountGood(int[] nums, int k) {
        long res = 0;
var count = new Dictionary<int, int>();
for (int i = 0, j = 0; j < nums.Length; ++j)
{
    k -= count.GetValueOrDefault(nums[j]);
    count[nums[j]] = count.GetValueOrDefault(nums[j]) + 1;

    while (k <= 0)
    {
        // first decrement by 1 as we are removing element from window
        count[nums[i]] = count[nums[i]] - 1;
        // as we want to add back (n-1)(n-1)/2 pairs instead of n(n-1)/2
        k += count[nums[i]];
        i++;
    }
    
    res += i;
}
return res;
    }
}