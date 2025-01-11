public class Solution {
    public bool CanConstruct(string s, int k) {
        if(s.Length<k) return false;
        HashSet<char> set = new HashSet<char>();
        foreach(char c in s){
            if(!set.Add(c)) set.Remove(c);
        }
        return set.Count<=k;
    }
}