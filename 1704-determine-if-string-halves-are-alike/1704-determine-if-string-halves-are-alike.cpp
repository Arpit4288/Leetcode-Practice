class Solution {
public:
    bool halvesAreAlike(string s) {
        int vow1 = 0, vow2 = 0;
        for(int i = 0;i<s.length();i++){
            if(toupper(s[i]) == 'A' || toupper(s[i]) == 'E' || toupper(s[i]) == 'I' || toupper(s[i]) == 'O' || toupper(s[i]) == 'U'){
                if(i < s.length()/2) vow1++;
                else vow2++;
            }
        }
        // cout<<vow<<endl;
        return vow1 == vow2;
    }
};