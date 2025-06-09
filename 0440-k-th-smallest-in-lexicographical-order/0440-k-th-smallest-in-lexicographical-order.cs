public class Solution {
    public int FindKthNumber(int n, int k) {
        int cur = 1;
        k--;

        while(k > 0){
            long steps = 0; long prefix1 = cur; long prefix2 = cur + 1;
            while(prefix1 <= n){
                steps += Math.Min((long)n + 1, prefix2) - prefix1;
                prefix1 *= 10;
                prefix2 *= 10;
            }

            if (steps <= k){
                cur++;
                k -= (int)steps;
            }else{
                cur *= 10;
                k--;
            }
        }

        return cur;
    }
}