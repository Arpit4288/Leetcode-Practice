class Solution {
public:

    vector<int> dp;

    int rec(int n){
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = n;
        for(int i = 1;i*i <= n;i++){
            ans = min(ans, 1 + rec(n-(i*i)));
        }
        dp[n] = ans;
        return ans;
    }
    int numSquares(int n) {
        dp.resize(n+1, -1);
        if(n <= 3) return n;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        int ans = rec(n);
        return ans;
    }
};