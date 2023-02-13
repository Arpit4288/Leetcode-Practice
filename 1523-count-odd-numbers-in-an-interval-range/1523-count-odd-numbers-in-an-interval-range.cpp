class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2 != 0 && high%2 != 0){
            return (ceil(high-low)/2.0)+1;
        }
        double ans = ceil(((double)high - (double)low)/2.0);
        return ans;
    }
};