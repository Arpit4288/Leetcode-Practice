class Solution {
public:
    int strStr(string s, string match) {
        int prev = 0, curr = 0;  // two pointer of window
        if(s.size() < match.size()) -1;  // if s is already small by match then there is not possible any answer
        int res = -1;   // if we can't find any such index then we have to return result as -1
        while(curr < s.size()){
            if(curr - prev + 1 == match.size()){  // if window size is equal to the size of match then we have to check weather this is equal to match or not if not then move window ahead 1 step
                if(s.substr(prev, match.size()) == match) return prev;
                else{
                    prev++;
                    curr++;
                }
            }
            else curr++;
        }
        return res;
    }
};