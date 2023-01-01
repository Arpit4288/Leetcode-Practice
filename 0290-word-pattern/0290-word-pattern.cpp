class Solution {
public:
    bool wordPattern(string pat1, string s) {
        vector<string> words;
        string word = "";
        for(int i = 0;i<s.length();i++){
            if(s[i] == ' '){
                words.emplace_back(word);
                word = "";
            }
            else word += s[i];
        }
        words.emplace_back(word);
        if(words.size() != pat1.length()) return false;
        
        unordered_map<char,string> mp;
        unordered_map<string,char> mp2;
        string pat2 = "";
        for(int i = 0;i<words.size();i++){
            if(mp.find(pat1[i]) == mp.end()){
                if(mp2.find(words[i]) != mp2.end()) return false;
                pat2 += pat1[i];
                mp[pat1[i]] = words[i];
                mp2[words[i]] = pat1[i];
            }
            else{
                if(mp[pat1[i]] != words[i]){
                    return false;
                }
                pat2 += pat1[i];
            }
        }
        
        return true;
    }
};