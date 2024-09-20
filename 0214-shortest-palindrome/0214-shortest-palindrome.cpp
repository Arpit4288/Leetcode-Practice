class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty())
            return s;

        // Create a new string that is the original + '#' + reversed
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined = s + "#" + rev_s;

        // KMP partial match (prefix-suffix array)
        vector<int> lps(combined.size(), 0); // Longest prefix suffix array

        // Build the LPS array for the combined string
        for (int i = 1; i < combined.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }

        // lps.back() gives us the length of the longest palindrome prefix
        int longest_palindrome_prefix_length = lps.back();

        // The characters to add are the part of the reverse of s that comes
        // after the palindrome prefix
        string to_add =
            rev_s.substr(0, s.size() - longest_palindrome_prefix_length);

        return to_add + s;
    }
};