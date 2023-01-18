class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int totalSum = 0, minSum = INT_MAX, maxSum = INT_MIN, currMinSum = 0, currMaxSum = 0;
        for(int i = 0;i<arr.size();i++){
            totalSum += arr[i];
            currMaxSum += arr[i];
            currMinSum += arr[i];
            maxSum = max(maxSum, currMaxSum);
            if(currMaxSum < 0) currMaxSum = 0;
            
            minSum = min(minSum, currMinSum);
            if(currMinSum > 0) currMinSum = 0;
        }
        // cout<<totalSum<<" "<<maxSum<<" "<<minSum<<" "<<currMaxSum<<" "<<currMinSum<<endl;
        int ans = INT_MIN;
        if(totalSum == minSum){ // all negative case
            return maxSum; // maxSum returnred maximum value in all negative
        }
        // Now either two cases happen either our maxSum (in simple array) is our ans or totalSum-minSum (if we leave minsumarray all the remaining in circlular form)
        ans = max(maxSum, totalSum - minSum);
        return ans;
    }
};