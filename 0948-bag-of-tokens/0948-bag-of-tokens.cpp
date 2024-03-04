#include <vector>
#include <algorithm>

class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        std::sort(tokens.begin(), tokens.end());
        
        int score = 0, maxScore = 0;
        int left = 0, right = tokens.size() - 1;
        
        while (left <= right) {
            // Play face-up if current power is enough
            if (power >= tokens[left]) {
                power -= tokens[left++];
                score++;
                maxScore = std::max(maxScore, score);
            }
            // Play face-down if score is positive
            else if (score > 0) {
                power += tokens[right--];
                score--;
            }
            // Unable to play either face-up or face-down
            else {
                break;
            }
        }
        
        return maxScore;
    }
};
