class Solution {
public:
    int searchInsert(vector<int>& arr, int t) {
        int n = arr.size();
        int i = 0, j = n-1;
        long long int mid;
        while(i<=j){
            mid = i + (j-i)/2;
            if(arr[mid] == t) return mid;
            else if(arr[mid] > t) j = mid-1;
            else i = mid+1;
        }
        return i;
    }
};