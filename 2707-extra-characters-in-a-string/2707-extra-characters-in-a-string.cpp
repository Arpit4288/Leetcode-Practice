class Solution {
public:
    
    unordered_map<string, bool> map;
    
    int findMin(int pos, string &s, vector<int> &dp){
        if(pos >= s.size()) return 0;
        if(dp[pos] != -1) return dp[pos];
        string curr = "";
        int ans = s.size();
        
        for(int i = pos; i< s.size(); i++){
            curr += s[i];
            int extraCount = curr.size();
            if(map[curr]){
                extraCount = 0;
            }
            extraCount += findMin(i + 1, s, dp);
            ans = min(ans, extraCount);
        }
        return dp[pos] = ans;
        
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto it : dictionary){
            map[it] = true;
        }
       
        
        vector<int> dp(s.size(), -1);
        return findMin(0, s, dp);
    }
};