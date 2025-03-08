public class Solution {
    public int MinimumRecolors(string blocks, int k) {
        int n = blocks.Length;
        int[] prefixWhite = new int[n + 1]; 
        for (int i = 0; i < n; i++) {
            prefixWhite[i + 1] = prefixWhite[i] + (blocks[i] == 'W' ? 1 : 0);
        }

        int minOperations = int.MaxValue;

        for (int i = 0; i <= n - k; i++) {
            int whiteCount = prefixWhite[i + k] - prefixWhite[i];
            minOperations = Math.Min(minOperations, whiteCount);
        }

        return minOperations;
    }
}