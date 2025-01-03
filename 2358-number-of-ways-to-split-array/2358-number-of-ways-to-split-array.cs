public class Solution {
    public int WaysToSplitArray(int[] arr) {
        long totalSum = 0;
        int n = arr.Length;
        for(int i = 0; i < n; i++){
            totalSum += arr[i];
        }

        int ans = 0;
        long currLSum = 0;
        for(int i = 0; i < n-1; i++){
           currLSum += arr[i];
           if(currLSum >= totalSum - currLSum) ans++;
        }
        return ans;
    }
}