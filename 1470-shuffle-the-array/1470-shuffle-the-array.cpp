class Solution {
public:
    vector<int> shuffle(vector<int>& arr, int n) {
        vector<int> ans; // initialze for storing the suffled elements of given array
        for(int i = 0, j  = n; i < n && j < 2*n;i++,j++){ // first index starting from 0, and second index starting from middle of the array and at each iteration we have to move both by one, till the end
            ans.emplace_back(arr[i]);
            ans.emplace_back(arr[j]);
        }
        return ans;
    }
};