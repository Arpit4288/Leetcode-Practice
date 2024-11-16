class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int i,j;
        vector<int>ans;
        int max=0;
        int count=0;
        int n=nums.size();
        if(k==1){
            for(i=0;i<n;i++){
            ans.push_back(nums[i]);}
            return ans;
        }
        for(i=0;i<=(n-k);i++){
            for(j=i;j<(i+k-1);j++){
            if(nums[j+1]>nums[j]){
                if((nums[j+1]-1)==(nums[j])){
                max=nums[j+1];
                }
                else{
                    max=-1;
                    break;
                }
            }
            else{
                max=-1;
                break;
            }
            }
            ans.push_back(max);

        }
        return ans;
    }
};