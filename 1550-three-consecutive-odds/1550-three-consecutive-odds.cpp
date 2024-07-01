class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCnt = 0; 
        for(auto & num : arr){
            if(num % 2 == 0)oddCnt = 0;
            else oddCnt++;
            if(oddCnt == 3)return true;
        }
        return false;
    }
};