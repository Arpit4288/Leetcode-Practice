public class Solution {
    public int[][] DivideArray(int[] nums, int k) {
        List<int[]> result = new List<int[]>();
        Array.Sort(nums);
        int cnt = 0;
        List<int> temp = new List<int>();

        for (int i = nums.Length - 1; i >= 0; i--) {
            cnt++;
            temp.Add(nums[i]);
            if (cnt == 3) {
                result.Add(temp.ToArray());
                temp.Clear();
                cnt = 0;
            }
        }

        foreach (var group in result) {
            Array.Sort(group); 
            if (group[2] - group[0] > k) {
                return new int[0][]; 
            }
        }

        return result.ToArray();
    }
}