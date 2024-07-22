class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> mp;
        for(int i = 0;i<names.size();i++){
            mp[heights[i]] = names[i];
        }
        sort(heights.begin(),heights.end());
        int idx = 0;
        for(int i = heights.size()-1;i>=0;i--){
            names[idx++] = mp[heights[i]];
        }
        return names;
        
    }
};