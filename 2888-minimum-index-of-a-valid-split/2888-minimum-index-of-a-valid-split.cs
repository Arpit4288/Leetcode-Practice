public class Solution {
    public int MinimumIndex(IList<int> nums) {
        int n = nums.Count;

        int candidate = -1, count = 0;
        foreach (int num in nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        int totalOccurrences = 0;
        foreach (int num in nums) {
            if (num == candidate) {
                totalOccurrences++;
            }
        }

        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) {
                leftCount++;
            }

            int leftSize = i + 1;
            int rightSize = n - leftSize;
            int rightCount = totalOccurrences - leftCount;

            if (leftCount * 2 > leftSize && rightCount * 2 > rightSize) {
                return i;
            }
        }

        return -1;
    }
}