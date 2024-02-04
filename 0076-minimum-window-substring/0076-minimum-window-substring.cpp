class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        unordered_map<char, int> mps, mpt;
        int minilen = INT_MAX;
        for(int i = 0;i<t.length();i++) mpt[t[i]]++;
        
        
        /* we are using sliding window of prev --> curr on s */
        int prev = 0, curr = 0;
        
        
        /* taking a variable of window size */
        int countletters = 0;
        
        /* Iterating on S */
        while(curr < s.length()){
            
            
            /* if s[curr] finds in mpt */
            if(mpt.find(s[curr]) != mpt.end()){
                if(mps[s[curr]] < mpt[s[curr]]) countletters++;
                mps[s[curr]]++;
            }
            if(countletters >= t.length()){
                while(mpt.find(s[prev]) == mpt.end() || mps[s[prev]] > mpt[s[prev]]){
                    mps[s[prev]]--;
                    prev++;
                }
                if(curr - prev + 1 < minilen){
                    minilen = curr-prev+1;
                    ans = s.substr(prev, minilen);
                }
            }
            curr++;
        }
        return ans;
    }
};