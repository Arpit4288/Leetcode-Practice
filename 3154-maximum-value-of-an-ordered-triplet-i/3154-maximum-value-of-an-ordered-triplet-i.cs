public class Solution {
    public long MaximumTripletValue(int[] arr) {
        int n = arr.Length;
        int[] storeRightMax = new int[n];
        int[] storeLeftMax = new int[n];

        int maxi = arr[n - 1];
        for(int i = arr.Length - 1; i >= 0; i--){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
            storeRightMax[i] = maxi;
            // Console.Write(maxi + " , " + mini);
            // Console.WriteLine();
        }

        maxi = arr[0];
        for(int i = 0; i < arr.Length; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
            storeLeftMax[i] = maxi;
            // Console.Write(maxi + " , " + mini);
            // Console.WriteLine();
        }

        long ans = 0;
        for(int i = 1; i < n - 1; i++){
            long trip = (long)(storeLeftMax[i - 1] - arr[i]) * storeRightMax[i + 1];
            // Console.WriteLine(trip + " >> Left MAX: " + storeLeftMax[i - 1] + " Right MAX: " + storeRightMax[i + 1]);
            if(trip > ans) ans = trip;
        }

        return ans;
    }
}