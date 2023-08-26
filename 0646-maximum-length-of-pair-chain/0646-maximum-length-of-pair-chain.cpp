class Solution {
public:
    // Greedy Approach
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        
        int prev = INT_MIN, curr = 0, ans = 0;
        while(curr < pairs.size()){
            if(prev < pairs[curr][0]){
                ans++;
                prev = pairs[curr][1];
            }
            curr++;
        }
        return ans;
    }
    
    
    
};