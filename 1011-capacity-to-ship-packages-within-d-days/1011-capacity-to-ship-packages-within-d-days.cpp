class Solution {
public:
    
    bool check(vector<int> &arr, int d, int mid){
        int sum = 0;
        int countD = 0;
        for(int i = 0;i<arr.size();i++){
            if(sum + arr[i] > mid){
                countD++;
                sum = 0;
            }
            sum += arr[i];
        }
        countD++;
        if(countD > d){
            return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& arr, int d) {
        int low = 0, high = 0;
        for(int i = 0;i<arr.size();i++){
            low = max(low, arr[i]);
            high += arr[i];
        }
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(arr, d, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};