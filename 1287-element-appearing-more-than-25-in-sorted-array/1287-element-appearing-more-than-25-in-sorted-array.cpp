class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int number;
        int n = arr.size();
        int quarter = n/4;
        if(n == 1) return arr[0];
        
        for(int i = 0; i<n-quarter; i++){
            if(arr[i] == arr[i + quarter]){
                number = arr[i];
                break;
            }
        }
        
        return number;
    }
};