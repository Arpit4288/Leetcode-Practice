public class Solution {
    public long CountInterestingSubarrays(IList<int> nums, int mod, int k) {
        var count = new Dictionary<int, long>();
        count[0] = 1; 

        long res = 0;
        int prefix = 0;

        foreach (int num in nums) {
            if (num % mod == k)
                prefix++;

            int currMod = prefix % mod;

            int needMod = (currMod - k + mod) % mod;

            if (count.ContainsKey(needMod))
                res += count[needMod];

            if (!count.ContainsKey(currMod))
                count[currMod] = 0;

            count[currMod]++;
        }

        return res;
    }
}