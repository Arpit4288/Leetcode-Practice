public class Solution 
{
    public IList<string> GetLongestSubsequence(string[] words, int[] groups) 
    {
        int state = groups[0];
        IList<string> result = new List<string>{words[0]};

        for(int i=0; i < words.Length; i++)
        {
            if(state != groups[i])
            {
                state = groups[i];
                result.Add(words[i]);
            }
        }

        return result;
    }
}