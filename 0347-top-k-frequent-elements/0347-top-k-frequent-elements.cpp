class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> vec;
        for(auto it : mp){
            // cout<<it.first<<" : "<<it.second<<endl;
            vec.emplace_back(make_pair(it.second, it.first));
        }
        sort(vec.begin(), vec.end());
        vector<int> ans;
        for(int i = 0;i<k;i++){
            ans.emplace_back(vec[vec.size()-1-i].second);
        }
        return ans;
    }
};