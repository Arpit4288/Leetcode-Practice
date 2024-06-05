class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        //step 1
        vector<int> fre(26,0);
        vector<int> currentString(26, 0);
        vector<string> res;
        if(words.size() == 1) return words;

        for(auto ch : words[0])
            fre[ch - 'a']++;
        for(int i = 1; i < words.size(); i++)
        {
            string word = words[i];
            //step 2
            for(auto ch : word)
            {   
                if(fre[ch-'a'] && currentString[ch - 'a'] < fre[ch - 'a'])
                    currentString[ch-'a']++; 
            }
            //step 3
            for(int k = 0; k < 26; k++)
            {
                fre[k] = currentString[k];
                currentString[k] = 0;
            }
        }
        //step 4
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < fre[i]; j++)
            {
                string s(1, 'a' + i);
                res.push_back(s);
            }   
        }
        return res;
        
    }
};