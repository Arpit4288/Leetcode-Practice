class Solution {
public:
    int rightmost(vector<int> &arr, long long x){
        int  low = 0, high = arr.size()-1;
        int ans = -1;
        int mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(arr[mid] > x){
                high = mid-1;
            }
            else{
                if(arr[mid] == x){
                    ans = mid;
                }
                low = mid+1;
            }
        }
        return ans;
        
    }
    
    int leftmost(vector<int> &arr, long long x){
        int  low = 0, high = arr.size()-1;
        int ans = -1;
        int mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(arr[mid] == x){
                ans = mid;
                high = mid-1;
            }
            else{
                if(arr[mid] > x) high = mid-1;
                else low = mid+1;
            }
        }
        // if(arr[mid] == x) return mid;
        return ans;
        
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> ans;
        ans.emplace_back(leftmost(arr, target));
        ans.emplace_back(rightmost(arr, target));
        return ans;
    }
};