public class Solution {
    public bool CanJump(int[] arr) {
        if(arr.Count() > 1 && arr[0] == 0) return false;

        int maxIdx = 0;

        for(int i = 0; i < arr.Length; i++){
            if(maxIdx >= arr.Count() - 1) return true;
            if(i + arr[i] < maxIdx) continue;
            else{
                if(i > maxIdx) return false;
                maxIdx = i + arr[i];
            }
        }
        return false;
    }
}