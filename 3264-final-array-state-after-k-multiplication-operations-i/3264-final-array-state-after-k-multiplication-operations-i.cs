public class Solution {
    public int[] GetFinalState(int[] arr, int k, int multiplier) {
        int minValue = Int32.MaxValue;
        int pos = -1;
        int n = arr.Length;
        for(int i = 0; i < k; i++){
            for(int j = n-1; j >= 0; j--){
                if(minValue >= arr[j]){
                    minValue = arr[j];
                    pos = j;
                }
            }
            arr[pos] = arr[pos]*multiplier;
            minValue = Int32.MaxValue;
            pos = -1;
        }
        return arr;
    }
}