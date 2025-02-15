public class Solution {
    public IList<int> FindDuplicates(int[] nums) {
        IList<int> result = new List<int>();
        
        foreach (int num in nums) {
            int index = System.Math.Abs(num) - 1;
            if (nums[index] < 0) {
                result.Add(index + 1);
            } else {
                nums[index] = -nums[index];
            }
        }
        
        // if you want to keep original array same otherwise we can skip
        foreach (int num in nums) {
            int index = System.Math.Abs(num) - 1;
            nums[index] = -nums[index];
        }
        
        return result;
    }
}