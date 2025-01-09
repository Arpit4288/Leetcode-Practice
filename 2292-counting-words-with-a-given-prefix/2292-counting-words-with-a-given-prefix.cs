public class Solution {
    public int PrefixCount(string[] words, string pref) {
        int ans = 0;
        for(int i = 0; i < words.Count(); i++){
            int curr = 0;
            for(int j = 0; j < words[i].Length; j++){
                if(curr > pref.Length - 1) break;
                if(pref[curr] == words[i][j]){
                    curr++;
                    continue;
                }
                else break;
            }
            if(curr > pref.Length - 1) ans++;
        }
        return ans;
    }
}