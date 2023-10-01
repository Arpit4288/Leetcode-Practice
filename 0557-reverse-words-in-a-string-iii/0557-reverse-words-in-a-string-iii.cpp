class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while(j < s.size()){
            if(s[j+1] == ' ' || j == s.size() - 1){
                int prevJ = j;
                while(i < j){
                    swap(s[i], s[j]);
                    i++;
                    j--;
                }
                i = j = prevJ + 2;
            }
            else j++;
        }
        return s;
    }
};