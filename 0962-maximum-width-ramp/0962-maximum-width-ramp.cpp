class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(); // size of the input array
        vector<int> maxSuff(n, -1e9); // suffix array to store max elements from i to n-1
        
        // Initialize maxSuff with maximum elements from the right
        maxSuff[n-1] = nums[n-1]; // last element is just nums[n-1]
        for(int i=n-2; i>=0; i--) {
            maxSuff[i] = max(maxSuff[i+1], nums[i]); // max element from i to n-1
        }
        
        int ans = -1e9; // variable to store the maximum width ramp
        
        // Loop through each element in nums
        for(int i=0; i<n; i++) {
            int num = nums[i];
            int temp;
            int l = i;
            int h = n-1;
            
            // Binary search to find the farthest j such that nums[i] <= maxSuff[j]
            while(l<=h) {
                int mid = l + (h-l)/2; // middle index
                if(maxSuff[mid] >= num) {
                    temp = mid; // store the current valid j
                    l = mid + 1; // try to find a farther j
                }
                else {
                    h = mid - 1; // if maxSuff[mid] < nums[i], move left
                }
            }
            
            // Calculate the ramp width and update the answer
            ans = max(ans, temp - i);
        }
        
        return ans; // return the maximum ramp width
    }
};