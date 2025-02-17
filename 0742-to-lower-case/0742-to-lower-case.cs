public class Solution {
    public string ToLowerCase(string s) {
        string ans = "";
        for(int i = 0; i < s.Length; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                ans += (char)(s[i] + 32);
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
}