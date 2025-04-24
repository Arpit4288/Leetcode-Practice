public class Solution
{
    public int CountCompleteSubarrays(int[] nums)
    {
        int[] freq = new int[2008];
        int distinctCount = 0,
            left = 0,
            right = 0,
            ans = 0,
            currentDistinctCount = 0;
        foreach (int num in nums)
        {
            if (freq[num] == 0)
            {
                distinctCount++;
            }
            freq[num]++;
        }

        Array.Fill(freq, 0);
        while (right < nums.Length)
        {
            if (freq[nums[right]] == 0)
            {
                currentDistinctCount++;
            }
            freq[nums[right]]++;
            while (currentDistinctCount == distinctCount && left <= right)
            {
                if (freq[nums[left]] > 1)
                {
                    freq[nums[left]]--;
                    left++;
                }
                else
                {
                    ans += left + 1;
                    break;
                }
            }
            right++;
        }
        return ans;
    }
}