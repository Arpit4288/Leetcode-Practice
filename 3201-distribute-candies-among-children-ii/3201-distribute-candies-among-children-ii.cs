public class Solution {
    public long DistributeCandies(int n, int limit) {
        long ans=0;

        int firstMin=Math.Max(0,n-2*limit);
        int firstMax=Math.Min(limit,n);

        for(int i=firstMin;i<=firstMax;i++)
        {
            int secondMin = Math.Max(0,n-i-limit);
            int secondMax= Math.Min(limit,n-i);

            ans+=secondMax-secondMin+1;
        }

        return ans;
    }
}