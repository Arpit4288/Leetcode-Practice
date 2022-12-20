class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> countStrings;
        vector<string> morseCode{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto word : words){
            string updatedString = "";
            for(auto c : word){
                updatedString += morseCode[c-'a'];
            }
            countStrings.insert(updatedString);
        }
        return countStrings.size();
        return 0;
    }
};