class Solution {
public:
    
    bool issafe(string s1, string s2){
        for(int i = 0;i<s1.length(); i += s2.length()){
            if(s1.substr(i,s2.length()) != s2) return false;
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        string pre = "";
        for(int i = 0;i<s.length()/2;i++){
            pre += s[i];
            if(issafe(s, pre) == true) return true;
        }
        return false;
    }
};