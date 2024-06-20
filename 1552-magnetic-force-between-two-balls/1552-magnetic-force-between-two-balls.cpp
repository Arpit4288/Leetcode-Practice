class Solution {
public:
    int maxDistance(vector<int>& arr, int m) {
        sort(arr.begin(), arr.end());
        int low = 0, high = arr[arr.size()-1];
        int ans = INT_MIN;
        while(low <= high){
            int mid = low +  (high - low)/2;
            int cnt = 1;
            int prev = 0;
            for(int i = 1;i<arr.size();i++){
                if(arr[i] - arr[prev] >= mid ){
                    prev = i;
                    cnt++;
                }
            }
            if(cnt>= m){
                ans = max(ans, mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};