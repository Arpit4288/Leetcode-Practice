class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int t) {
        vector<int> ans;
        long long int n = arr.size();
        unordered_map<int,int> mp;
        for(long long int i = 0;i<n;i++){
            if(mp.find(t-arr[i]) != mp.end()){
                long long temp = t-arr[i];
                ans.emplace_back(mp[temp]);
                ans.emplace_back(i);
                return ans;
            }
            else mp[arr[i]] = i;
        }
        return ans;
    }
};