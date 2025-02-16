public class Solution {
    public string RemoveDuplicateLetters(string s) {
        int[] freq = new int[26];
        bool[] visited = new bool[26];
        Array.Fill(visited, false);
        Stack<char> st = new Stack<char>();
        for(int i = 0; i < s.Length; i++){
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < s.Length; i++){
            if(visited[s[i] - 'a']){
                freq[s[i] - 'a']--;
                continue;
            }
            while(st.Count() > 0 && st.Peek() > s[i] && freq[st.Peek() - 'a'] > 0){
                visited[st.Peek() - 'a'] = false;
                st.Pop();
            }
            st.Push(s[i]);
            visited[s[i] - 'a'] = true;
            freq[s[i] - 'a']--;
        }
        string ans = "";
        while(st.Count() > 0){
            ans = st.Peek() + ans;
            st.Pop();
        }
        return ans;
    }
}