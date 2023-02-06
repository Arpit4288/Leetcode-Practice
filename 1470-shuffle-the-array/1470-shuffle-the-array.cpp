class Solution {
public:
    vector<int> shuffle(vector<int>& arr, int n) {
        vector<int> ans;
        for(int i = 0, j  = n; i < n && j < 2*n;i++,j++){
            ans.emplace_back(arr[i]);
            ans.emplace_back(arr[j]);
        }
        return ans;
    }
};