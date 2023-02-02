class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if(s1 + s2 != s2 + s1) return "";   // it is prety sures that if both are not equal then it is not possible that both was formed by same substr hence return ""
        int len = __gcd(s1.size(), s2.size());  // the dividable string have the size equal to the gcd of s1.size(), s2.size() tbhi toh dono ko devide krega
        return s1.substr(0, len);
    }
};