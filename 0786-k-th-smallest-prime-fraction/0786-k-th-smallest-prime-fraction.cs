public class Solution {
     public int[] KthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.Length;
        double left = 0.0, right = 1.0;

        while (left < right) {
            double mid = (left + right) / 2;
            int[] result = CountFractions(arr, mid);
            int count = result[0];

            if (count < k) {
                left = mid;
            } else if (count > k) {
                right = mid;
            } else {
                return new int[]{result[1], result[2]};
            }
        }

        return new int[]{};
    }
     private int[] CountFractions(int[] arr, double target) {
        int count = 0;
        int numerator = 0, denominator = 1;

        for (int i = -1, j = 0; i < arr.Length - 1; i++) {
            while (j < arr.Length && arr[i + 1] > target * arr[j]) {
                j++;
            }
            count += arr.Length - j;
            if (j < arr.Length && (numerator * arr[j] < denominator * arr[i + 1])) {
                numerator = arr[i + 1];
                denominator = arr[j];
            }
        }

        return new int[]{count, numerator, denominator};
    }
}