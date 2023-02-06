class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;  // for storing the indexes of starting index of every anagram
        vector<int> freq1(26, 0);  // stores the frequency of every character 
        for(int i = 0;i<p.length();i++){
            freq1[p[i] - 'a']++; // Eg. a --> 0 : 1, b --> 1 : 1
        }
        int prev = 0, curr = 0;  // current window in 0
        vector<int> freq2(26, 0);  // storing the window elements frequency
        while(curr < s.length()){
            freq2[s[curr] - 'a']++;  // taking the curr character ino the window
            if(curr - prev + 1 > p.length()){  // if window size is greater than required
                freq2[s[prev] - 'a']--; // then previous character through out and remove its freq from freq2
                prev++;
            }
            if(curr - prev + 1 == p.length()){  // If window is full and window size is matched with p then we have to check is that window is matched with p or not if it match then store the starting index of that window into our ans
                if(freq1 == freq2){
                    // cout<<" Inside answering ";
                    ans.emplace_back(prev);
                }
            }
            curr++;
        }
        return ans;
    }
};