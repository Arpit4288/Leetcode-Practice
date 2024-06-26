class Solution {
public:
    int k;                  // Number of jars
    int res = INT_MAX;      // Result variable to store the minimum maximum jar value
    vector<int> d;          // Vector to store the current jar values

    void dfs(vector<int>& real, int index, int f) {
        if (index == real.size()) {   // Base case: If all cookies have been distributed
            int iron_man = 0;
            for (int i = 0; i < k; i++) {
                iron_man = max(iron_man, d[i]); // Find the maximum value among all jars
            }
            res = min(res, iron_man);       // Update the result with the minimum maximum jar value
            return;
        }

        for (int i = 0; i < f; i++) {
            d[i] += real[index];     // Distribute the cookie to jar 'i'
            dfs(real, index + 1, f); // Recurse to distribute the next cookie
            d[i] -= real[index];     // Backtrack: Remove the cookie from jar 'i'
        }

        if (f < k) {
            d[f] += real[index];     // Distribute the cookie to a new jar 'f'
            dfs(real, index + 1, f + 1); // Recurse to distribute the next cookie
            d[f] -= real[index];     // Backtrack: Remove the cookie from jar 'f'
        }
    }

    int distributeCookies(vector<int>& real, int K) {
        k = K;
        d.resize(K);                    // Resize the vector 'd' to 'K' jars
        dfs(real, 0, 0);
        return res;
    }
};