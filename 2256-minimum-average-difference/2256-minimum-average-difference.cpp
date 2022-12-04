class Solution {
public:
    #define ll long long
    int minimumAverageDifference(vector<int>& arr) {
        ll tSum = 0;
        for(auto it : arr) tSum += it;
        ll currSum = 0;
        ll ansIdx = INT_MAX, ansAvg = INT_MAX;
        for(int i = 0;i<arr.size();i++){
            ll leftSum = 0, rightSum = 0;
            currSum += arr[i];
            leftSum = currSum;
            rightSum = tSum-currSum;
            ll leftAvg, rightAvg;
            leftAvg = leftSum/(i+1);
            if(i == arr.size()-1) rightAvg = 0;
            else rightAvg = rightSum/(arr.size()-(i+1));
            
            ll avgDiff = abs(leftAvg - rightAvg);
            if(avgDiff < ansAvg){
                ansAvg = avgDiff;
                ansIdx = i;
            }
        }
        return ansIdx;
        
    }
};