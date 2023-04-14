class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.length(),i,j;
        vector<int> dp(n+1,0),tmp(n+1,0);
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[j] = tmp[j-1]+1;
                }else{
                    dp[j] = max(dp[j-1],tmp[j]);
                }
            }
            // for(auto &i: dp)cout<<i<<" ";
            // cout<<endl;
            tmp = dp;
        }
        return dp[n];
    }
};