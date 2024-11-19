class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_set<int> st;

        int i = 0;
        int j = 0;
        int n = nums.size();

        long long maxAns = 0;
        long long sum    = 0;

        while(j < n){

            //Removing duplicates from the current Window
            while(st.find(nums[j]) != st.end()){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }   

            st.insert(nums[j]);
            sum += nums[j];

            if(j - i + 1 == k){//Updating answer in "k" size window

                maxAns = max(maxAns, sum);
                
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }

        return maxAns;
    }
};