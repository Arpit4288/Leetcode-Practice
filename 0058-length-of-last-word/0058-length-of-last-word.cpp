class Solution {
public:
    int lengthOfLastWord(string s) {
        int curr = s.length()-1;
        while(s[curr] == ' ' && curr >= 0){
            if(s[curr] == ' ') curr--;
            else break;
        }
        int cnt = 0;
        while(curr >= 0 && s[curr] != ' '){
            curr--;
            cnt++;
        }
        return cnt;
    }
};