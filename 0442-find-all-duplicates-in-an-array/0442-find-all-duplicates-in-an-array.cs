public class Solution {
    public IList<int> FindDuplicates(int[] nums) {
        int[] arr = new int[nums.Length + 1];
        
        for(int i = 0; i < nums.Length; i++){
            if(arr[nums[i]] == 0) arr[nums[i]] = 1;
            else arr[nums[i]] = -1;
        }
        IList<int> list = new List<int>();
        for(int i = 1; i < arr.Length; i++){
            if(arr[i] == -1) list.Add(i);
        }
        return list;
    }
}