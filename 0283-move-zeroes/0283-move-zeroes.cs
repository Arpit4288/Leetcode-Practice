public class Solution {
    public void MoveZeroes(int[] arr) {
        int slow = 0, fast = 0;
        while(fast < arr.Length){
            if(arr[fast] != 0){
                (arr[slow], arr[fast]) = (arr[fast], arr[slow]);
                slow++;
            }
            fast++;
        }
    }
}