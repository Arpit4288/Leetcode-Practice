class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Create an unordered map to store the prefix sums and their frequencies.
        unordered_map<int,int> mp;
        // Initialize the sum variable to 0.
        int sum=0;
        // Initialize the map with 0 as a prefix sum with a frequency of 1.
        mp[0]=1;
        // Initialize the answer variable to 0.
        int ans=0;
        // Iterate through the input array.
        for(int i=0;i<nums.size();i++){
            // Update the sum by adding the current element of the array.
            sum+=nums[i];
            // Check if there exists a prefix sum such that (sum - goal).
            if(mp.find(sum-goal)!=mp.end()){
                // If such a prefix sum exists, update the answer by adding its frequency.
                ans+=mp[sum-goal];
            }
            // Increment the frequency of the current prefix sum.
            mp[sum]++;
        }
        // Return the final answer.
        return ans;
    }
};