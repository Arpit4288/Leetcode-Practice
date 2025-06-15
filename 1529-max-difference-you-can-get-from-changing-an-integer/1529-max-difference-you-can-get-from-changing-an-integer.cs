public class Solution {
    public int MaxDiff(int num) {
        int minn = num;
        int maxn = num;
        string s = num.ToString(); 
        if (s[0] != '1') 
        {
            minn = Convert.ToInt32(s.Replace(s[0], '1'));
        }
        else
        {
            for (int i = 1; i < s.Length; i++) {
                    if (s[i] != '0' && s[i] != '1') {
                        minn = Convert.ToInt32(s.Replace(s[i], '0'));
                        break;
                    }
                }
        }

        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] != '9')
            {
                maxn = Convert.ToInt32(s.Replace(s[i], '9'));
                break;
            }
        }
        int diff = maxn - minn;
        return diff;
    }
}