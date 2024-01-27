class Solution {
    const int mod = 1e9+7;
    
    
public:
    int kInversePairs(int n, int k) {
        vector<vector<long long>> dp(n+1,vector<long long>(k+1,0));
        for(int i = 0 ; i<=k ; i++){
            dp[0][i]=1;
        }
        
        for(int i = 1 ; i<=n ;i++) {
            for(int j=0 ; j<=k ; j++) {
                if(j==0){
                    dp[i][j]=1;
                }else{
                    if(j-i+1<=0){
                    dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                    }else{
                    dp[i][j]=(dp[i][j]+dp[i-1][j]-dp[i-1][j-i]+mod)%mod;
                    }
                    if(i!=n){
                    dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
                    }
                   
                }
            }
        }

        return (int)dp[n][k];

        
        
        
    }
};