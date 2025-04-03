public class Solution {
    public static bool isPossible(int[] arr, int k, int h){
        int currTime = 0;
        for(int i = 0; i < arr.Length; i++){
            currTime += (int)Math.Ceiling((double)arr[i] / (double)k);
            if(currTime > h) return false;
        }

        return currTime <= h;
    }

    public int MinEatingSpeed(int[] arr, int h) {
        int low = 1, high = int.MinValue;
        int n = arr.Length;
        for(int i = 0; i < n; i++) high = Math.Max(high, arr[i]);

        int ans = high;
        while(low < high){
            int mid = (low + high) / 2;
            if(isPossible(arr, mid, h)){
                high = mid;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;

    }
}