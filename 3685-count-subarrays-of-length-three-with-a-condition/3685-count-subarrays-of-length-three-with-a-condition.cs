public class Solution {
    public int CountSubarrays(int[] arr) {
        int n = arr.Length;

        int ans = 0;
        for(int i = 0; i < n -2; i++){
            if(arr[i + 1] % 2 != 0) continue;
            if(arr[i] + arr[i + 2] == arr[i + 1] / 2) ans++;
        }

        return ans;
    }
}