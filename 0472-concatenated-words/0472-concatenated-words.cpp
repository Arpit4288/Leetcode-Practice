class Solution {
public:
    
    bool checkIfContac(string &s, unordered_set<string> &st){
        for(int i = 1;i<s.length();i++){  // traversing the string from 1th index
            string pref = s.substr(0, i); // word froms from 0 to i (prefix)
            string suff = s.substr(i, s.length()-i);  // word form from i+1 to end (suffix)
            // if pref is find in set then also the suff or it finds in many break point(joining by anothers find by recursion) then it clearly says that it can be form by given words in a words array
            if(st.find(pref) != st.end() && (st.find(suff) != st.end() || checkIfContac(suff, st))) return true;
        }
        return false;  // otherwise return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st;
        for(auto word : words) st.insert(word);
        vector<string> ans;
        for(auto word : words){
            if(checkIfContac(word, st) == true) ans.emplace_back(word);
        }
        return ans;
        
    }
};



