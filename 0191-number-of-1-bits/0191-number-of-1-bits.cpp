class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        string binaryString = bitset<32>(n).to_string();
        for (char c : binaryString) {
            if (c == '1') {
                count++;
            }
        }
        return count;
    }
};