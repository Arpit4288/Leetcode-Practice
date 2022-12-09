class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1, mp2;
        if(s.length() != t.length()) return false;
        for(int i = 0;i<s.length();i++){
            if(mp1.find(s[i]) == mp1.end()){
                if(mp2.find(t[i]) != mp2.end()) return false;
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
                s[i] = t[i];
            }
            else{
                if(t[i] != mp1[s[i]]) return false;
                s[i] = mp1[s[i]];
            }
        }
        return true;
    }
};