class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int> qu(arr.begin(), arr.end());
        int ans;
        for(int i = 0;i<k;i++){
            ans = qu.top();
            qu.pop();
        }
        return ans;
        
    }
};