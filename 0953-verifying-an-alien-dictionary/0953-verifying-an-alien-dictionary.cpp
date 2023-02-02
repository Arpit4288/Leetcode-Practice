class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> mp;  // storing the character which are change due to Aliens dict h --> a here h in alien and a in our dict
        for(char c = 'a'; c<= 'z';c++){
            mp[order[c-'a']] = c;
        }
        
        for(int i = 0;i<words.size();i++){  // changing the characters of aliens words in our words with there order
            for(auto &c : words[i]) c = mp[c];
        }
        for(int i = 1;i<words.size();i++){  // comparing simply becase it is in our language now and comparing function internaly compares the strings in according to our dict
            if(words[i] < words[i-1]) return false;
        }
        return true;
    }
};