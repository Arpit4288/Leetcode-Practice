public class Solution {
    public int BeautifulSubsets(int[] nums, int k) {
        // Sort the numbers so we can gaurantee x - k condition will always be smaller.
        Array.Sort(nums);
        return Count(nums, 0, k, new HashSet<int>());
    }

    private int Count(int[] nums, int index, int k, HashSet<int> mem){
        if(index == nums.Length){
            return mem.Count == 0 ? 0 : 1;
        }

        // Classic set / backtracking take me or don't take me.
        //Don't take me case. Increment index to next value, don't add to memorization table.
        var sum = Count(nums, index+1, k, mem);

        // Take me case. But only take me if "currentItem" - k doesn't equal a previously seen value.
        // E.G 2, 4, 6 test case.
        // Add 2 to hashset.
        // 4 - 2 = 2, 2 exists in hashset so do not add 4 to 2's subset.
        if(!mem.Contains(nums[index] - k)){
            mem.Add(nums[index]);
            sum += Count(nums, index + 1,  k, mem);
            // Backtrack, so that this number is not longer considered.
            mem.Remove(nums[index]);
        }
        return sum;
    }
}