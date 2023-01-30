class Solution {
public:
    int rec(int n, vector<int> &dp){
        if(n == 0) return dp[n] = 0;
        if(n <= 2) return dp[n] = 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] =  (rec(n-3, dp) + rec(n-2, dp) + rec(n-1, dp));
    }
    int tribonacci(int n) {
        vector<int> dp(n+2, -1);
        return rec(n, dp);
        
    }
};