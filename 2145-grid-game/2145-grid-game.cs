public class Solution {
    public long GridGame(int[][] grid) 
    {
        int n = grid[0].Length;
        long [] prefix1 = new long[n];
        long [] prefix2 = new long[n];
        prefix1[0] = grid[0][0];
        prefix2[0] = grid[1][0];
        for(int i = 1; i < n; i++)
        {
            prefix1[i] = prefix1[i-1] + grid[0][i];  
            prefix2[i] = prefix2[i-1] + grid[1][i];   
        }
        long sum = 0, index = -1;
        for(int i = 0; i < n; i++)
        {
            if(prefix1[i] + prefix2[i] > sum)
            {
                sum = prefix1[i] + prefix2[i];
                index = i;
            }
        }
        long ans = long.MaxValue;
        for(int i = 0; i < n; i++)
        {
            long topRight = prefix1[n-1] - prefix1[i];
            long bottomLeft = i == 0? 0 :  prefix2[i-1];
            ans = Math.Min(ans, Math.Max(topRight, bottomLeft));
        }
        return ans;
    }
}