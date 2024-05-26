#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    ll n;
    ll dp[100001][3][4];
    ll solve(int index, int abst, int ltcns) {
        if (abst >= 2)
            return 0;

        if (ltcns >= 3)
            return 0;

        if (index == n)
            return 1;

        if (dp[index][abst][ltcns] != -1)
            return dp[index][abst][ltcns];

        return dp[index][abst][ltcns] =
                   (solve(index + 1, abst, 0) % mod +
                    solve(index + 1, abst + 1, 0) % mod +
                    solve(index + 1, abst, ltcns + 1) % mod) %
                   mod;
    }
    ll checkRecord(int n) {
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};