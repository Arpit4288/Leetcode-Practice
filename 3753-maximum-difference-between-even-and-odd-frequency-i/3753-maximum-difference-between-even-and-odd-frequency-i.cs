public class Solution {
    public int MaxDifference(string s) {
        int[] frequency = new int[26];
        for (int i = 0; i < s.Length; i++) {
            frequency[(int)(s[i] - 'a')]++;
        }
        int maxFreq = 0, minFreq = 101;
        for (int i = 0; i < 26; i++) {
            if (frequency[i] == 0) {
                continue;
            }
            if (frequency[i] % 2 == 0) {
                minFreq = Math.Min(minFreq, frequency[i]);
            } else {
                maxFreq = Math.Max(maxFreq, frequency[i]);
            }
        }
        return maxFreq - minFreq;
    }
}