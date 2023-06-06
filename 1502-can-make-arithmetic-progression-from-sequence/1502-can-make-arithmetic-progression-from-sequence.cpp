class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(n == 2) return true;
        int diff;
        for(int i =1;i<n;i++){
            if(i == 1) diff = arr[i]-arr[i-1];
            else if(arr[i]-arr[i-1] != diff) return false;
        }
        return true;
    }
};