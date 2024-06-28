#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-for-loops")
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(0); cin.tie(0);
        vector<int> numConnections(n, 0);
        for (const auto& v : roads) {
            for (const int x : v) {
                ++numConnections[x];
            }
        }
        sort(numConnections.begin(), numConnections.end());
        long long res = 0;
        for (int i = 0; i < numConnections.size(); ++i) {
            res += (long(i + 1) * long(numConnections[i]));
        }
        return res;
    }
};