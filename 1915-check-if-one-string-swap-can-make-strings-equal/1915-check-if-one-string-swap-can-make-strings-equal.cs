public class Solution {
    public bool AreAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int first = -1, second = -1;
        int count = 0;
        for(int i = 0; i < s1.Length; i++){
            if(s1[i] != s2[i]){
                count++;
                if(count == 1) first = i;
                else second = i;
            }
        }
        if(count != 2) return false;
        string v1 = s1[first].ToString() + s1[second].ToString();
        string v2 = s2[first].ToString() + s2[second].ToString();
        string v3 = v1[1].ToString() + v1[0].ToString();
        Console.WriteLine(v1.Reverse().ToString() + "   " + v2);
        return v1 == v2 || v3 == v2;
    }
}