public class Solution {
    public int[] ApplyOperations(int[] arr) {
        for (int i = 0; i < arr.Length - 1; i++) {
            if(arr[i] == arr[i + 1]){
                arr[i] *= 2;
                arr[i + 1] = 0;
            }
        }

        int slow = 0, fast = 0;
        while(fast < arr.Length){
            if(arr[fast] != 0){
                (arr[slow], arr[fast]) = (arr[fast], arr[slow]);
                slow++;
            }
            fast++;
        }
        return arr;
    }
}