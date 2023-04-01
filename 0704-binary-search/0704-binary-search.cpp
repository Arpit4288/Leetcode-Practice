class Solution {
public:
    int search(vector<int>& arr, int t) {
        int n = arr.size();
        int i = 0,j = n-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(arr[mid] == t) return mid;
            if(arr[mid] > t) j = mid-1;
            else i = mid+1;
        }
        return -1;
    }
};