class Solution {
public:
int mod = 1e9+7;
    int countHomogenous(string s) {
        int n = s.size();
        char pre='8';
        long long ct=0;
        long long ans=0;
        for(int i=0; i<n; i++){
            if(s[i]==pre){
                ct++;
            }else{
                ans = (ans + (ct%mod*(ct+1)%mod)/2)%mod;
                ct=1;
                pre=s[i];
            }
        }
        ans = (ans + (ct%mod*(ct+1)%mod)/2)%mod;
        return ans;
    }
};