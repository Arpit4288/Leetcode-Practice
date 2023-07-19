class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 0;
        int prev = 0, curr = 1;
        while(curr < arr.size()){
            if(arr[curr][0] < arr[prev][1]){
                cnt++;
                if(arr[curr][1] < arr[prev][1]){
                    prev = curr;
                    curr++;
                }
                else{
                    curr++;
                }
            }
            else{
                prev = curr;
                curr++;
            }
        }
        return cnt;
    }
};