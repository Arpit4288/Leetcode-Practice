class Solution {
public:
    bool same(string s){
        sort(s.begin(), s.end());
        return s[0]==s.back();
    }
    bool has(string &s, int n){
        unordered_map<string, int>mp;
        for(int i = 0;i+n<=s.length();i++){
            string aux =  s.substr(i, n);
            if(same(aux))
                mp[aux]++;
            if(mp[aux]>=3)
                return true;
        }
        return false;
    }
    int maximumLength(string s) {
        int n = s.length();
        int ans = -1;
        for(int i = 1;i<n;i++){
            if(has(s, i))
                ans = i;
        }
        return ans;
    }
};