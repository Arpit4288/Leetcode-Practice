public class Solution {
    public int NumberOfSubstrings(string s) {
        int[] counters = new int[3];
int result = 0, head = 0, tail = 0, uniques = 0;
for (; head < s.Length;)
{
    if (counters[s[head++] - 'a']++ == 0) uniques++;
    while (uniques == 3)
    {
        result += s.Length - head + 1;
        if (--counters[s[tail++] - 'a'] == 0) uniques--;
    }
}
return result;
    }
}