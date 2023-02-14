class Solution {
public:
    string addBinary(string s1, string s2) {
        int diff = abs((int)s1.size()-(int)s2.size());
        if(s1.size() < s2.size()){
            for(int i = 0;i<diff;i++){
                s1 = '0' + s1;
            }
        }
        else{
            for(int i = 0;i<diff;i++){
                s2 = '0' + s2;
            }
        }
        int rem = 0;
        int sum = 0;
        string ans = "";
        for(int i = s1.size()-1;i>=0;i--){
            sum = int(s1[i]-'0') + int(s2[i]-'0') + rem;
            if(sum == 0){
                rem = 0;
            }
            else if(sum == 1){
                rem = 0;
            }
            else if(sum == 2){
                sum = 0;
                rem = 1;
            }
            else if(sum == 3){
                sum = 1;
                rem = 1;
            }
            ans = to_string(sum) + ans;
        }
        if(rem == 1) ans = to_string(rem) + ans;
        return ans;
    }
};