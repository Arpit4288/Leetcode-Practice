class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> ans;
        for (auto it : allowed) {
            ans.insert(it);
        }
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            bool f1 = true;
            for (auto it : words[i]) {
                if (ans.find(it) == ans.end()) {
                    f1 = false;
                    break;
                }
            }
            if (f1) {
                count++;
            }
        }
        return count;
    }
};