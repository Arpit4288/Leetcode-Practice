class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        vector<int> arr(temp.size(), 0);
        st.push(make_pair(temp[temp.size()-1], temp.size()-1));
        for(int i = temp.size()-2;i>=0;i--){
            while(!st.empty() && temp[i] >= st.top().first){
                st.pop();
            }
            if(st.size() > 0){
                arr[i] = st.top().second - i;
            }
            st.push(make_pair(temp[i], i));
        }
        return arr;
    }
};