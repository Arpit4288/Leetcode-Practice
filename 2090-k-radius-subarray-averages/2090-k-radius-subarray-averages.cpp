class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        // Size of sliding window
        int windowSize = 2 * k + 1;

        // Initialize result of size n with all -1
        vector<int> result(n, -1);

        // using long long for avoiding integer overflow
        long long total = 0;

        for(int i = 0; i < n; i++){
            // Add the element to the total
            total += nums[i];
         
            // If we are at the end of the window then store the result
            if(i >= windowSize - 1){
                // store the result  
                result[i - windowSize / 2] = total / windowSize;

                // removing the first element from window to not overflow the window on next iteration
                total -= nums[i - windowSize + 1];
            }
        }

        return result;
    }
};