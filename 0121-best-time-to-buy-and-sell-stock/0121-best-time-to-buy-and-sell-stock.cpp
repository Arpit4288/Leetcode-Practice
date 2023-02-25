class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        int maxlen = INT_MIN;
        int minlen = INT_MAX;
        int maxprof = INT_MIN;
        for(int i = 0;i<n;i++){
            if(i == 0){
                maxlen = arr[0];
                minlen = arr[0];
            }
            else if(maxlen < arr[i]){
                maxlen = arr[i];
                maxprof = max(maxprof,maxlen-minlen);
            }
            if(minlen > arr[i]){
                minlen = arr[i];
                maxlen = arr[i];
            }            
        }
        if(maxprof == INT_MIN) return 0;
        return maxprof;
    }
};