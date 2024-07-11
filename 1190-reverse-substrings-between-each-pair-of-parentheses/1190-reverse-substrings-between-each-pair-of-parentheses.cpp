class Solution {
    int i = 0;
    string reverseString(string& s) {
        string result = "";
        
        while (i < s.length()) {
            if (s[i] == '(') {
                i++;
                string st = reverseString(s);
                result += st;
            } else if (s[i] == ')') {
                reverse(result.begin(), result.end());
                i++;
                return result;
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }

public:
    string reverseParentheses(string s) {
        int i=0;
         return reverseString(s); }
};