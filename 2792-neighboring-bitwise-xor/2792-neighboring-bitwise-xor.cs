public class Solution {
    public bool DoesValidArrayExist(int[] derived) {
          int n = derived.Length;
        
        // Try to construct the original array with original[0] = 0
        int[] original = new int[n];
        original[0] = 0;
        
        // Propagate the values based on the XOR relations
        for (int i = 0; i < n - 1; i++) {
            original[i + 1] = derived[i] ^ original[i];
        }
        
        // Check the last condition: derived[n-1] == original[n-1] ⊕ original[0]
        if (derived[n - 1] == (original[n - 1] ^ original[0])) {
            return true;
        }
        
        return false;
    }
}