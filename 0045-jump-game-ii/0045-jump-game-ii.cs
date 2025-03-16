public class Solution {
    public int Jump(int[] arr) {
        int n = arr.Count();

        int l = 0, r = 0;
        int jumps = 0;

        while(r < n -1){
            int farthest = 0;
            for(int i = l; i <= r; i++){
                farthest = Math.Max(i + arr[i], farthest);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
}