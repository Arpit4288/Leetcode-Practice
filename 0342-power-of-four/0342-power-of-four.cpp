class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int numberOfSetBit = __builtin_popcount(n);
        int countTrailingZero = __builtin_ctz(n);
        if(numberOfSetBit==1 && countTrailingZero%2==0) return true;
        return false;
    }
};