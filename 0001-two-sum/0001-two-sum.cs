public class Solution {
    public int[] TwoSum(int[] arr, int t) {
        Dictionary<int, int> dict = new();

        int[] res = new int[2];
        for(int i = 0; i < arr.Length; i++){
            if(dict.ContainsKey(arr[i])){
                res[0] = dict[arr[i]];
                res[1] = i;
                return res;
            }
            else{
                dict[t - arr[i]] = i;
            }
        }
        return new int[2];
    }
}