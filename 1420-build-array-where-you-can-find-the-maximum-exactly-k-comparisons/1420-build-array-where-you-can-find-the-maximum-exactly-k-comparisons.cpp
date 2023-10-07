class Solution {
public:
    int mod = 1e9+7;
    int f(int sz, int cur, int n, int m, int k, vector<vector<vector<int>>>& dp){
        if(sz==n){
            return k==0;
        }
        if(k<0) return 0;
        if(dp[sz][cur][k]!=-1) return dp[sz][cur][k];
        int ans = 0;
        for(int i = 1; i<=m; i++){
            ans+=f(sz+1,max(i,cur),n,m,k - ((i>cur)?:0),dp)%mod;
            ans%=mod;
        }
        return dp[sz][cur][k] = ans;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return f(0,0,n,m,k,dp);
    }
};