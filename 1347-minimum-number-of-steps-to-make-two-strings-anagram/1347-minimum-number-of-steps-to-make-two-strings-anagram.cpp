#define IOS ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
class Solution {
public:
    int minSteps(string s, string t) {
        IOS
        unordered_map<char,int>m;
        for(int i= 0 ; i<s.size() ; i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        int ans = 0;
        for(auto i : m){
            if( i.second>0 ) ans += i.second;
        }
        return ans ;
    }
};