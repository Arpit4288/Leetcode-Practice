class Solution {
public:
    vector<int> mp;
    string customSortString(string order, string s) {
        mp.resize(26);
        for(int i = 0;i < order.size();i++) mp[order[i]-'a'] = i+1;
        sort(s.begin(), s.end(), [&](char &a, char &b){
            return mp[a-'a'] < mp[b-'a'];
        });
        return s;
    }
};