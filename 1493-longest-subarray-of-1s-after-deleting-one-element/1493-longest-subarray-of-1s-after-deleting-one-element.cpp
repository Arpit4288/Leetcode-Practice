class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=(int)nums.size();
        
        if(n==1){
            return 0;
        }
        if(count(nums.begin(),nums.end(),0)==0){
            return n-1;
        }
        
        int cnt=0;
        vector<int> tot;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                tot.push_back(cnt);
                tot.push_back(0);
                cnt=0;
            }
            else{
                cnt++;
            }
        }
        if(cnt){
            tot.push_back(cnt);
        }
        int res=0;
        for(int i=0;i<(int)tot.size();i++){
            if(i-1>=0 and i+1<(int)tot.size() and tot[i]==0 and tot[i-1]>0 and tot[i+1]>0){
                res=max(res,tot[i-1]+tot[i+1]);
            }
            else if(i-1>=0 and i+1<(int)tot.size()){
                if(tot[i]==0 and tot[i-1]>0){
                    res=max(res,tot[i-1]);
                }
                if(tot[i+1]>0 and tot[i]==0){
                    res=max(res,tot[i+1]);
                }
            }
        }
        return res;
    }
};