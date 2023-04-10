class Solution {
public:
    bool match(char c1, char c2){
        if(c1 == '(' && c2 == ')') return true;
        if(c1 == '{' && c2 == '}') return true;
        if(c1 == '[' && c2 == ']') return true;
        else return false;
    }
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0;i<n;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else{
                if(st.empty() || !match(st.top(), s[i])) return false;
                else st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};