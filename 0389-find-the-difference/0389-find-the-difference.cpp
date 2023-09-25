class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for(auto it : s){
            mp[it]++;
        }
        char ans;
        
        for(auto it : t){
            if(mp.find(it) == mp.end() || mp[it] == 0){
                ans = it;
                break;
            }
            mp[it]--;
        }
        return ans;
    }
};