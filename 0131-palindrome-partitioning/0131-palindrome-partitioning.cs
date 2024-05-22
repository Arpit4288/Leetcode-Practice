public class Solution {
    public IList<IList<string>> Partition(string s) {
        IList<IList<string>> result = new List<IList<string>>();
        List<string> current = new List<string>();
        bool[][] isPalindrome = new bool[s.Length][];

        for (int i = 0; i < s.Length; i++) {
            isPalindrome[i] = new bool[s.Length];
        }

        PartitionHelper(s, 0, current, result, isPalindrome);
        return result;
    }

    private void PartitionHelper(string s, int start, List<string> current, IList<IList<string>> result, bool[][] isPalindrome) {
        if (start >= s.Length) {
            result.Add(new List<string>(current));
            return;
        }

        for (int end = start; end < s.Length; end++) {
            if (s[start] == s[end] && (end - start <= 2 || isPalindrome[start + 1][end - 1])) {
                isPalindrome[start][end] = true;
                current.Add(s.Substring(start, end - start + 1));
                PartitionHelper(s, end + 1, current, result, isPalindrome);
                current.RemoveAt(current.Count - 1);
            }
        }
    }
}