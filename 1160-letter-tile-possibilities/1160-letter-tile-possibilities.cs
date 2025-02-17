public class Solution {
    public int NumTilePossibilities(string tiles) {
        int[] count = new int[26]; 
        foreach (char c in tiles) {
            count[c - 'A']++; 
        }
        return Backtrack(count);
    }
    private int Backtrack(int[] count) {
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) { 
                sum++; 
                count[i]--; 
                sum += Backtrack(count); 
                count[i]++; 
            }
        }
        return sum;
    }
}