class Solution {
public:
    bool isPalindrome(string s) {
        int idx = 0;
        for(int i = 0;i<s.length();i++){
            if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)){
                s[idx++] = tolower(s[i]);
            }
            if(s[i] >= 48 && s[i] <= 57) s[idx++] = s[i];
        }
        int low = 0, high = idx-1;
        // for(int i = 0;i<idx;i++) cout<<s[i]<<"  ";
        while(low < high){
            if(s[low] != s[high]) return false;
            low++;high--;
        }
        return true;
    }
};