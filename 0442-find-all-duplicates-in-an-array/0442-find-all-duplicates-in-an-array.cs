public class Solution {
    public IList<int> FindDuplicates(int[] arr) {
        IList<int> res = new List<int>();
        for(int i = 0; i < arr.Length; i++){
            int idx = Math.Abs(arr[i]) - 1;
            if(arr[idx] < 0){
                res.Add(idx + 1);
            }
            else arr[idx] = -arr[idx];
        }
        return res;
    }
}