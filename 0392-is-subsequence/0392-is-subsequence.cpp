class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idxs = 0;
        if(s == "") return true;
        for(int i = 0;i<t.size();i++){
            if(idxs > s.size()-1){
                return true;
            }
            if(t[i] == s[idxs]){
                idxs++;
                continue;
            }
        }
        if(idxs > s.size()-1){
            return true;
        }
        return false;
    }
};