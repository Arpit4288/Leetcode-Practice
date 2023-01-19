class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int currSum = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            currSum += arr[i];
            int rem = currSum % k;
            if(rem == 0) ans++;
            if(rem < 0) rem += k;
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};