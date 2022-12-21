class Solution {
public:
    bool isPalindrome(int x) {
        string curr = to_string(x);
        string after = curr;
        reverse(after.begin(), after.end());
        return (long long)stoll(curr) == (long long)stoll(after);
    }
};