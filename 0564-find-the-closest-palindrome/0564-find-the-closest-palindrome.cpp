class Solution {
public:
    long long int diff(string s, string t) {
        long long int a = stoll(s);
        long long int b = stoll(t);
        return abs(a - b);
    }
    string nearestPalindromic(string n) {
        if (n == "9") return "8";
        if (n == "11") return "9";
        if (n == "10") return "9";
        unordered_map<char, int> mp;
        for (auto it : n) mp[it]++;
        // case for only string contain 9 ex : 99 ans : 101
        if (mp.size() == 1) {
            if (mp.count('9')) {
                string x(n.size() + 1, '0');
                x[0] = x.back() = '1';
                return x;
            }
        }
        // case for only string contain 1 at start and mid 0 ex : 100  ans : 99
        if (mp.size() == 2) {
            if (mp.count('0') && mp.count('1') && mp['1'] == 1) {
                string x(n.size() - 1, '9');
                return x;
            }
        }
        // case for only string contain 1 at start and end and mid 0 ex : 101 ans : 99 
        if (mp.size() == 2) {
            if (mp.count('0') && mp.count('1') && mp['1'] == 2 &&
                n.back() == '1') {
                string x(n.size() - 1, '9');
                return x;
            }
        }
        // case for only string contain same num at start and end and mid 0 or 9
        // ex : 8998 ans : 9009 && 9009  ans: 8998 
        if (mp.size() == 2) {
            if (n.back() == n[0] && mp[n[0]] == 2) {
                if (n[1] == '0') {
                    string x(n.size(), '9');
                    x[0] = x.back() = n[0] - 1;
                    return x;
                }
                if (n[1] == '9') {
                    string x(n.size(), '0');
                    x[0] = x.back() = n[0] + 1;
                    return x;
                }
            }
        }
        // simple for other case 
        // 123111 just change: => 123321 bcz copy from left to right is nearest 
        string n1 = n;
        for (int i = 0, j = n.size() - 1; i <= j; i++, j--) {
            n[j] = n[i];
        }
        // mid find
        int m1 = n.size() / 2,
            m2 = n.size() / 2 - ((n.size() % 2 == 0) ? 1 : 0);
        long long int dif = 1e18;
        string ans;
        // check only which mid return min bcz we have te check
        // for 13   is optimal but for 19: 22 is optimal
        for (int i = 0; i < 10; i++) {
            string t = n;
            t[m1] = t[m2] = i + '0';
            long long int d = diff(t, n1);
            if (d != 0) {
                if (d < dif) {
                    dif = d;
                    ans = t;
                } else if (d == dif) {
                    if (t < ans)
                        ans = t;
                }
            }
        }
        return ans;
    }
};