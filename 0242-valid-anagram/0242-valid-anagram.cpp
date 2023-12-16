class Solution {
public:
    bool isAnagram(string s, string t) {
        int ns = s.length(), nt = t.length();
        if(ns != nt) return false;
        unordered_map<char,int> mp;
        for(int i = 0;i<ns;i++){
             mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it : mp) if(it.second != 0) return false;
        return true;
    }
};