class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        int i = 0,j = 0;
        string ans = "";
        while(i < n1 && j < n2){
            ans += s1[i];
            ans += s2[j];
            i++; j++;
        }
        while(i < n1){
            ans += s1[i];
            i++;
        };
        while(j <n2){
            ans += s2[j];
            j++;
        }
        return ans;
    }
};