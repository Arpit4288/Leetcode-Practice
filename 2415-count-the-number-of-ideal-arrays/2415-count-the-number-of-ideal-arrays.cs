public class Solution {
    const int MOD = 1000000007;
    const int MAX_N = 10010;
    const int MAX_P = 15;  // There are up to 15 prime factors
    int[,] c = new int[MAX_N + MAX_P, MAX_P + 1];
    int[] sieve = new int[MAX_N];           // Minimum prime factor
    List<int>[] ps = new List<int>[MAX_N];  // List of prime factor counts

    public Solution() {
        if (c[0, 0] == 1) {
            return;
        }
        for (int i = 0; i < MAX_N; i++) {
            ps[i] = new List<int>();
        }
        for (int i = 2; i < MAX_N; i++) {
            if (sieve[i] == 0) {
                for (int j = i; j < MAX_N; j += i) {
                    if (sieve[j] == 0) {
                        sieve[j] = i;
                    }
                }
            }
        }

        for (int i = 2; i < MAX_N; i++) {
            int x = i;
            while (x > 1) {
                int p = sieve[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                ps[i].Add(cnt);
            }
        }
        c[0, 0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) {
            c[i, 0] = 1;
            for (int j = 1; j <= Math.Min(i, MAX_P); j++) {
                c[i, j] = (c[i - 1, j] + c[i - 1, j - 1]) % MOD;
            }
        }
    }

    public int IdealArrays(int n, int maxValue) {
        long ans = 0;
        for (int x = 1; x <= maxValue; x++) {
            long mul = 1;
            foreach (var p in ps[x]) {
                mul = mul * c[n + p - 1, p] % MOD;
            }
            ans = (ans + mul) % MOD;
        }
        return (int)ans;
    }
}