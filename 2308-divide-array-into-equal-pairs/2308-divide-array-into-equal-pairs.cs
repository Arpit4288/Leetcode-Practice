public class Solution {
    public bool DivideArray(int[] arr) {
        int[] track = new int[501];
        // Array.Fill(track, -1);
        for(int i = 0; i < arr.Length; i++){
            track[arr[i]]++;
        }
        for(int i = 0; i < 501; i++){
            if(track[i] != 0){
                if(track[i] % 2 == 0) continue;
                return false;
            }
        }

        return true;
    }
}