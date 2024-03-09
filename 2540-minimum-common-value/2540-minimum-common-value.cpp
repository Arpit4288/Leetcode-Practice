class Solution {
public:
    int getCommon(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int i = 0;i<arr1.size();i++){
            st.insert(arr1[i]);
        }
        int ans = INT_MAX;
        for(int i = 0;i<arr2.size();i++){
            if(st.find(arr2[i]) != st.end()){
                ans = min(ans, arr2[i]);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};