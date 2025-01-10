public class Solution
{
    public IList<string> WordSubsets(string[] words1, string[] words2)
    {
        List<string> result = new List<string>();
        Dictionary<char, int> main = new Dictionary<char, int>();

        // Build the frequency template
        foreach (string word in words2)
        {
            Dictionary<char, int> dic = new Dictionary<char, int>();
            foreach (char c in word)
            {
                dic[c] = dic.GetValueOrDefault(c, 0) + 1;
            }
            foreach (var entry in dic)
            {
                main[entry.Key] = Math.Max(main.GetValueOrDefault(entry.Key, 0), entry.Value);
            }
        }

        // Check each word in words1 for universality
        foreach (string word in words1)
        {
            if (IsUniversal(main, word))
            {
                result.Add(word);
            }
        }

        return result;
    }

    private bool IsUniversal(Dictionary<char, int> template, string word)
    {
        Dictionary<char, int> wordFreq = new Dictionary<char, int>();
        foreach (char c in word)
        {
            wordFreq[c] = wordFreq.GetValueOrDefault(c, 0) + 1;
        }

        foreach (var entry in template)
        {
            if (wordFreq.GetValueOrDefault(entry.Key, 0) < entry.Value)
            {
                return false;
            }
        }

        return true;
    }
}