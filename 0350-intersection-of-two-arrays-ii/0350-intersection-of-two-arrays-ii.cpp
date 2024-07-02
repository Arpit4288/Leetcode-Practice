class Solution {
public:
    vector<int> intersect(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n1;i++) mp[arr1[i]]++;
        vector<int> ans;
        for(int i = 0;i<n2;i++){
            if(mp.find(arr2[i]) != mp.end() && mp[arr2[i]] > 0){
                ans.emplace_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        return ans;
        
    }
};