public class Solution {
    public bool IsArraySpecial(int[] nums) {
      //Sliding window
      if(nums.Length == 1) return true;

      int windowStart = 0;
      int windowEnd = 1;

      while(windowStart != nums.Length - 1){
        if(nums[windowStart] % 2 == nums[windowEnd] % 2) return false;
        windowStart++; windowEnd++;
      }
      return true;
    }
}