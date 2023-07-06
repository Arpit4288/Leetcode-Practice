class Solution {
public:
    int minSubArrayLen(int t, vector<int>& arr) {
        int ans = INT_MAX, l = 0, r = 0, currsum = 0;
        while(r < arr.size()){
            currsum += arr[r];
            if(currsum >= t){
                while(currsum >= t){
                    currsum -= arr[l++];
                }
                ans = min(ans, r-l+2);
            }
            r++;
        }
        return ans == INT_MAX ? 0: ans;
    }
};