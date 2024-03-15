class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        long long prod = 1;
        int cnt = 0;
        for(int i = 0;i<arr.size(); i++){
            if(arr[i] != 0) prod *= arr[i];
            if(arr[i] == 0) cnt++;
        }
        vector<int> ans(arr.size());
        if(cnt > 1){
            fill(ans.begin(), ans.end(), 0);
            return ans;
        }
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == 0) ans[i] = prod;
            else{
                if(cnt == 1) ans[i] = 0;
                else ans[i] = prod/arr[i];
            };
        }
        return ans;
    }
};