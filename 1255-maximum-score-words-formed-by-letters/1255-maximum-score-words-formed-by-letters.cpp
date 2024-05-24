class Solution {
public:
    // time/space: O(n^2 * m)/O(n)
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> letterCount;
        for (auto& c : letters) letterCount[c]++;
        unordered_map<char, int> charScore;
        for (char c = 'a'; c <= 'z'; c++) charScore[c] = score[c - 'a'];
        return helper(words, letterCount, charScore, 0);
    }
private:
    int helper(vector<string>& words, unordered_map<char, int>& letterCount, unordered_map<char, int>& charScore, int i) {
        // terminate
        if (i == words.size()) return 0;

        // enumerate (each word can be skipped or picked)
        int skip = helper(words, letterCount, charScore, i + 1);
        int pick = 0;

        // count the characters and the score in the word
        unordered_map<char, int> charCount;
        int score = 0;
        for (auto& c : words[i]) charCount[c]++, score += charScore[c];

        // if this word can be picked (letters are enough)
        if (canPick(charCount, letterCount)) {
            // pick the word
            for (auto& [c, f] : charCount) letterCount[c] -= f;
            // go to the next word
            pick = score + helper(words, letterCount, charScore, i + 1);
            // return the word
            for (auto& [c, f] : charCount) letterCount[c] += f;
        }
        return max(skip, pick);
    }
    bool canPick(unordered_map<char, int>& charCount, unordered_map<char, int>& letterCount) {
        for (auto& [c, f] : charCount) {
            if (f > letterCount[c]) return false;
        }
        return true;
    }
};