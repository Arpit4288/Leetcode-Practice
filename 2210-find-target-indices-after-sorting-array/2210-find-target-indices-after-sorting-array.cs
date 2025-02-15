public class Solution {
    public IList<int> TargetIndices(int[] nums, int target) {
        int smallerCount = 0, targetCount = 0;

        for(int i = 0; i < nums.Length; i++){
            if(nums[i] == target) targetCount++;
            else if(nums[i] < target) smallerCount++;
        }
        
        if(targetCount == 0) return new List<int>();
        else return Enumerable.Range(smallerCount, targetCount).ToArray();
    }
}