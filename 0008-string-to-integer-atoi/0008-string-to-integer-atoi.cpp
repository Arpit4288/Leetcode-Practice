class Solution {
public:
    int myAtoi(string s) {
        int sign = 0;
        bool flag = false;
        int i = 0;
        while(i < s.size()){
            if(s[i] == '+'){
                if(flag) return 0;
                flag = true;
                sign = 1;
                i++;
            }
            else if(s[i] == '-'){
                if(flag) return 0;
                flag = true;
                sign = -1;
                i++;
            }
            else if(s[i] == ' '){
                if(flag) return 0;
                i++;
            }
            else break;
        }
        s = s.substr(i);
        long long ans = 0;
        for(int i = 0;i<s.size();i++){
            if(ans > INT_MAX) ans = INT_MAX;
            if(ans < INT_MIN) ans = INT_MIN;
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                if(sign == -1) ans = ans*10 - (s[i] - '0');
                else ans = ans*10 + (s[i] - '0');
            }
            else break;
        }
        if(ans > INT_MAX) ans = INT_MAX;
        if(ans < INT_MIN) ans = INT_MIN;
        return ans;
    }
};