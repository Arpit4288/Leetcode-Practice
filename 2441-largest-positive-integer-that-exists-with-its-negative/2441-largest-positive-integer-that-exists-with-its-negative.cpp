class Solution {
public:
    int findMaxK(vector<int>& arr) {
        unordered_set<int> st;
        for(int i = 0;i<arr.size();i++) st.insert(arr[i]);
        int ans = -1;
        
        for(int i = 0;i<arr.size();i++){
            if(arr[i] > 0) if(st.find(-1*arr[i]) != st.end()) ans = max(abs(arr[i]), ans);
        }
        return ans;
    }
};