class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int>dp;

        vector<int> ans;
        for(int i = 0;i<arr.size();i++){
            if(!dp.empty() && dp.front() == i - k) dp.pop_front();
            while(!dp.empty() && arr[dp.back()] < arr[i]){
                dp.pop_back();
            }
            dp.emplace_back(i);
            if(i >= k-1) ans.emplace_back(arr[dp.front()]);
        }
        return ans;



    }
};