class Solution {
public:
    double average(vector<int>& sal) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0;i<sal.size();i++){
            sum += sal[i];
            mini = min(mini, sal[i]);
            maxi = max(maxi, sal[i]);
        }
        sum = sum - mini - maxi;
        double ans = (double)sum / (double)(sal.size()-2);
        return ans;
    }
};