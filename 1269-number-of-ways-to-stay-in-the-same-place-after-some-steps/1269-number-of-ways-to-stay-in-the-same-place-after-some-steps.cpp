class Solution {
public:
      //  int solve(int steps,int arrlen,int cnt,int st,vector<vector<int>>dp)
      //  {
      //    if(st>arrlen||st<1||cnt>steps)
      //    return 0;

      //    if(cnt==steps&&st==1)
      //    return 1;
      //    if(dp[cnt][st]!=-1)
      //    return dp[cnt][st];

      //    int ans=0;
      //     ans+=(solve(steps,arrlen,cnt+1,st-1,dp)+solve(steps,arrlen,cnt+1,st,dp)+solve(steps,arrlen,cnt+1,st+1,dp))%1000000007;

      //     return dp[cnt][st]=ans;
      //  }
     int numWays(int steps, int arrLen) {
    const int MOD = 1000000007;
     arrLen = min(steps, arrLen);
    vector<vector<int>> dp(steps + 1, vector<int>(arrLen + 1, 0));

    dp[0][1] = 1;  

    for (int i = 1; i <= steps; ++i) {
        for (int j = 1; j <= arrLen; ++j) {
          //Same Position
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;  
          //left side move
            if (j > 1)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;  
           //right Side move
            if (j < arrLen)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;  
        }
    }

    return dp[steps][1];
}

};