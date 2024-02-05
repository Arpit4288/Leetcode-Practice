class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int ans = -1;
        for(int i = n-1;i>=0;i--){
            mp[s[i]]++;
        }
        for(int i = 0;i<n;i++){
            if(mp[s[i]] == 1) return i;
        }
        return ans;
    }
};