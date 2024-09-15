class Solution {
public:
    int findTheLongestSubstring(string s) {
        int max_ = 0, n = s.size();
        vector<int> v(32, INT_MAX);
        v[0] = -1;
        int x = 0;
        for (int i = 0; i < n; ++i) {
            switch (s[i]) {
                case 'a': x ^= 1; break;
                case 'e': x ^= 2; break;
                case 'i': x ^= 4; break;
                case 'o': x ^= 8; break;
                case 'u': x ^= 16; break;
            }
            v[x] = min(v[x], i);
            max_ = max(max_, i - v[x]);
        }
        return max_;
    }
};
