public class Solution {
    public int CountPairs(int[] nums, int k) {
        int count = 0;
        int n = nums.Length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
}