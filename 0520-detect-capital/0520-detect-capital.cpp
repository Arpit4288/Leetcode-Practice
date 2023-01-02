class Solution {
public:
    
    bool isAllCap(string s){
        for(int i = 0;i<s.length();i++){
            if(s[i] >= 'a' && s[i] <= 'z') return false;
        }
        // cout<<"fdfdf";
        return true;
    }
    
    bool isAllSmall(string s){
        for(int i = 0;i<s.length();i++){
            if(s[i] >= 'A' && s[i] <= 'Z') return false;
        }
        return true;
    }
    
    bool isFirstCap(string s){
        if(s[0] >= 'A' && s[0] <= 'Z'){
            for(int i = 1;i<s.length();i++){
                if(s[i] >= 'A' && s[i] <= 'Z') return false;
            }
            return true;
        }
        return false;
    }
    
    bool detectCapitalUse(string word) {
        bool first = isAllCap(word), sec = isAllSmall(word), third = isFirstCap(word);
        // cout<<first<<" : "<<sec<<" : "<<third<<endl;
        return first || sec || third;
    }
};