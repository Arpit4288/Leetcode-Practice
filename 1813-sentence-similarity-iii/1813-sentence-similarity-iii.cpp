class Solution {
private:
    vector<string> convert(string s){
        istringstream iss(s);
        vector<string> result;
        string word;

        while (iss >> word) {
            result.push_back(word);
        }

        return result;
    }
    bool find(string s1,string s2){
        vector<string>str1=convert(s1);
        vector<string>str2=convert(s2);
        int n1=str1.size();
        int n2=str2.size();
        int i=0,j=0;
        //prefix
        while (i < n1 && i < n2 && str1[i] == str2[i]) {
            i++;
        }
        //suffix
        while (j < n1 - i && j < n2 - i && str1[n1 - 1 - j] == str2[n2 - 1 - j]) {
            j++;
        }
        //check if add up length is equals to either string length means bothh words are present with some other words in the middle
        return i + j == n1 || i + j == n2;
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        bool ans=false;
        if(n>m){
            ans=find(s2,s1);
        }
        else{
            ans=find(s1,s2);
        }
        return ans;
    }
};