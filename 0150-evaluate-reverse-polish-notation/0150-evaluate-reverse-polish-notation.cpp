class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "+"){
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                long long newpush = stoi(n2) + stoi(n1);
                st.push(to_string(newpush));
            }
            else if(tokens[i] == "-"){
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                long long newpush = stoi(n2) - stoi(n1);
                st.push(to_string(newpush));
            }
            else if(tokens[i] == "*"){
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                long long newpush = (long long)stoll(n2) * (long long)stoll(n1);
                st.push(to_string(newpush));
            }
            else if(tokens[i] == "/"){
                string n1 = st.top();
                st.pop();
                string n2 = st.top();
                st.pop();
                long long newpush = stoi(n2) / stoi(n1);
                st.push(to_string(newpush));
            }
            else{
                st.push(tokens[i]);
            }
        }
        string ans = st.top();
        return stoi(ans);
    }
};