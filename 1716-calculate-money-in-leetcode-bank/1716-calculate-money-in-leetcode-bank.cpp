class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        for(int i=1; i<=n; i++){
            if(i%7==0){
                ans+=(i/7)+7-1;
            }
            else{
                ans+=(i/7)+(i%7);
            }
        }
        return ans;
    }
};