class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(int i = 0;i<s.length();i++) mp[s[i]]++;
        int ans = 0;
        bool flag = 0;
        // for(auto it : mp){
        //     cout<<it.first<<"  "<<it.second<<endl;
        // }
        for(auto it : mp){
            if(it.second %2 == 0){
                ans += it.second;
            }
            else if(it.second % 2 != 0 && flag == 0){
                ans += it.second;
                flag = 1;
            }
            else if(it.second % 2 != 0 && flag == 1){
                ans += it.second -1;
            }
        }
        return ans;
    }
};