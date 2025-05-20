public class Solution {
    public bool IsZeroArray(int[] nums, int[][] queries) {
        Span<int> arr = stackalloc int[nums.Length + 1];

        foreach (var q in queries)
        {
            arr[q[0]]--;
            arr[q[1] + 1]++;
        }

        for (int i = 1; i < arr.Length; ++i)
        {
            arr[i] += arr[i - 1];
        }

        for (int i = 0; i < nums.Length; ++i)
        {
            if (nums[i] + arr[i] > 0) return false;
        }
        return true;
    }
}