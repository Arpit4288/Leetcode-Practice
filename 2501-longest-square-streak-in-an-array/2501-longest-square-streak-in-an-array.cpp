class Solution {
public:
    int longestSquareStreak(vector<int>& arr) {
        int limit = sqrt(INT_MAX);
        sort(arr.begin(), arr.end());
        int ans = -1;
        unordered_set<int> st;
        for(int i = 0;i<arr.size();i++) st.insert(arr[i]);
        for(int i = 0;i<arr.size();i++){
            int count = 1;
            if(arr[i] > limit){
                // cout<<"continue at : "<<arr[i]<<endl;
                continue;
            }
            else{
                int next = arr[i]*arr[i];
                int flag = 0;
                while(flag == 0 && st.find(next) != st.end()){
                    count++;
                    if(next > limit){
                        // cout<<"inside break at : "<<count<<endl;
                        flag = 1;
                    }
                    else{
                        next = next*next;
                    }
                }
            }
            if(count >= 2){
                if(count > ans) ans = count;
            }
        }
        return ans;
    }
};