public class Solution {
    public int[] ClosestPrimes(int left, int right) {
        List<int> primes = new List<int>();

        for (int num = left; num <= right; num++) {
            if (IsPrime(num)) {
                primes.Add(num);
            }
        }
        if (primes.Count < 2) {
            return new int[] { -1, -1 };
        }
        int minDiff = int.MaxValue;
        int num1 = -1, num2 = -1;

        for (int i = 1; i < primes.Count; i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                num1 = primes[i - 1];
                num2 = primes[i];
            }
        }

        return new int[] { num1, num2 };
    }
    private bool IsPrime(int n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
}