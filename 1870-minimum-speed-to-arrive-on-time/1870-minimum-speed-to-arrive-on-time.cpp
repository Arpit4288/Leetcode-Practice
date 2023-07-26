class Solution {
public:
    
    bool check(vector<int> &arr, double hour, int k){
        double cnt = 0;
        for(int i = 0;i<arr.size()-1;i++){
            cnt += ceil((double)arr[i] / (double)k);
        }
        cnt += (double)arr[arr.size()-1] / (double)k;
        // cout<<cnt<<endl;
        return cnt <= hour;
    }
    
    int minSpeedOnTime(vector<int>& arr, double hour) {
        int l = 1, h = 10000000;
        int ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(check(arr, hour, mid)){
                ans = mid;
                h  = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};