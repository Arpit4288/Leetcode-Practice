class Solution
{
public:
       string makeGood(string &s)
       {
              if (s.empty() || s.length() == 1)
              {
                     return s;
              }

              bool removed = false;

              for (int i = 0; i < s.length() - 1; i++)
              {
                     if (abs(s[i] - s[i + 1]) == 32)
                     {
                            removed = true;
                            s.erase(s.begin() + i);
                            s.erase(s.begin() + i);
                            break;
                     }
              }

              if (!removed)
              {
                     return s;
              }
              else
              {
                     return makeGood(s);
              }
       }
};