public class Solution
    {
        public string ShortestCommonSupersequence(string str1, string str2)
        {
            int[,] dp = new int[str1.Length + 1, str2.Length + 1];
            for (int i = 1; i <= str1.Length; i++)
            {
                for (int j = 1; j <= str2.Length; j++)
                {
                    if (str1[i - 1] == str2[j - 1])
                    {
                        dp[i, j] = dp[i - 1, j - 1] + 1;
                    }
                    else
                    {
                        dp[i, j] = Math.Max(dp[i - 1, j], dp[i, j - 1]);
                    }
                }
            }
            int m = str1.Length;
            int n = str2.Length;
            string lcs = string.Empty;
            while (m > 0 && n > 0)
            {
                if (dp[m - 1, n] == dp[m, n])
                {
                    m--;
                }
                else if (dp[m, n - 1] == dp[m, n])
                {
                    n--;
                }
                else
                {
                    lcs = str1[m - 1] + lcs;
                    m--;
                    n--;
                }
            }
            string result = string.Empty;
            m = 0;
            n = 0;
            foreach (char ch in lcs)
            {
                for (int i = m; i < str1.Length; i++)
                {
                    if (str1[i] != ch)
                    {
                        result += str1[i];
                    }
                    else
                    {
                        m = i + 1;
                        break;
                    }
                }
                for (int i = n; i < str2.Length; i++)
                {
                    if (str2[i] != ch)
                    {
                        result += str2[i];
                    }
                    else
                    {
                        n = i + 1;
                        break;
                    }
                }
                result += ch;
            }
            while (m < str1.Length)
            {
                result += str1[m];
                m++;
            }
            while (n < str2.Length)
            {
                result += str2[n];
                n++;
            }
            return result;
        }
    }