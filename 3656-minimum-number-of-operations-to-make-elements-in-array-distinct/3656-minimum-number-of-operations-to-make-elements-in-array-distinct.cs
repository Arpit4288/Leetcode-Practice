public class Solution {
    public int MinimumOperations(int[] arr) {
        int n = arr.Length;
        if(n == 1) return 0;
        if(n == 2) return arr[0] == arr[1] ? 1 : 0;

        HashSet<int> st = new HashSet<int>();

        for(int i = n - 1; i >= 0; i--){
            if(st.Contains(arr[i])){
                int l = i + 1;
                return (int)Math.Ceiling((i + 1) / 3.0);
            }
            else{
                st.Add(arr[i]);
            }
        }

        return 0;

    }
}