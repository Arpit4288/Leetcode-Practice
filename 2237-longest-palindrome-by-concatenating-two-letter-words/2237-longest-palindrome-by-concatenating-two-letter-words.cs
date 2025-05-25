public class Solution 
{
    public int LongestPalindrome(string[] words) 
    {
        // Span for max.performance
        Span<int> dict = stackalloc int[676];
        
        // Build frequency dictionary
        foreach (var word in words)
        {
            int idx = 26 * (word[0] - 'a') + (word[1] - 'a');
            dict[idx]++;
        }

        int result = 0;
        bool hasCentral = false; // is central palindrome
        
        // Process all possible word combinations
        for (int idx = 0; idx < dict.Length; idx++)
        {
            int count = dict[idx];
            if (count == 0) continue;

            int firstChar = idx / 26;
            int secondChar = idx % 26;
            
            if (firstChar == secondChar) // Palindrome words
            {
                result += count / 2 * 4; // Add even pairs
                if (count % 2 == 1) hasCentral = true;
            }
            else if (firstChar < secondChar) // Process pairs only once
            {
                int mirrorIdx = secondChar * 26 + firstChar;
                int mirrorCount = dict[mirrorIdx];
                
                if (mirrorCount > 0)
                {
                    // Add minimum matching pairs
                    result += Math.Min(count, mirrorCount) * 4;
                    dict[mirrorIdx] = 0; // Mark as processed
                }
            }
        }

        return result + (hasCentral ? 2 : 0); // Add central pair if needed
    }
}