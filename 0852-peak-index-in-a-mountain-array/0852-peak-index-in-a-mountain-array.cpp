class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n-1;
        while(i<=j){
            long int mid = i + (j-i)/2;
            if(mid == 0){
                i = mid+1;
                continue;
            }
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            if(arr[mid] > arr[mid+1]) j = mid - 1;
            else i = mid + 1;
        }
        return -1;
    }
};