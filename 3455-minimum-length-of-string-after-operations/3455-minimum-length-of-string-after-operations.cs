public class Solution
{
    public int MinimumLength(string s)
    {
        Dictionary<char, int> chars = new Dictionary<char, int>();
        int result = 0;
        foreach (char c in s)
        {
            if (chars.ContainsKey(c))
            {
                chars[c]++;
            }
            else
            {
                chars.Add(c, 1);
            }
        }
        foreach (char c in chars.Keys)
        {
            if (chars[c] % 2 == 0)
            {
                result += 2;
            }
            else result += 1;
        }
        return result;
    }
}