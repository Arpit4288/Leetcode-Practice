class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        while(low < high){
            int mid = low + ((high - low) / 2);
            if(mid == 0){
                if(arr[mid] != arr[mid+1]) return arr[mid];
            }
            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
            if(arr[mid] == arr[mid-1]){
                int leftLen, rightLen;
                leftLen = mid - low + 1;
                rightLen = high - mid;
                if(leftLen % 2 != 0){
                    high = mid;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                int leftLen, rightLen;
                leftLen = mid - low;
                rightLen = high - mid + 1;
                if(leftLen % 2 != 0){
                    high = mid-1;
                }
                else{
                    low = mid;
                }
            }
        }
        return arr[low];
    }
};