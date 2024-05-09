public class Solution {
    public long MaximumHappinessSum(int[] happiness, int k) {
        long happy=0;
        Array.Sort(happiness, (a,b)=>b-a);
        for(int i=0;i<k;i++){
            happy += happiness[i]>i? happiness[i]-i:0;
        }
        return happy;
    }
}