class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
    int leftSide,rightSide;
    leftSide = k;
    rightSide = k;
    int mini = nums[k]; // Make the potential ans as minimum value and compare other values with it
    int ans = nums[k];  // The potential answer
    
    while(leftSide > 0 || rightSide < nums.size() - 1)  // Here we'll check for left side or right or both 
    {
        if(leftSide > 0 && rightSide < nums.size() -1)  // To check for left and right both sides ,i.e [3,7] and [7,4] both sides of k
        {
            if(nums[leftSide - 1] > nums[rightSide + 1]) // if left is bigger we'll select smaller value from left
            {
                leftSide--;
                mini = min(mini,nums[leftSide]);
            }
            else  // if right is bigger we'll select smaller value from right
            {
                rightSide++;
                mini = min(mini,nums[rightSide]);
            }
        }
        else if(leftSide >0)  // to check all the value on left
        {
            leftSide--;  //shift to only left
            mini = min(mini,nums[leftSide]);
        }
        else  // To check all the values on right
        { 
            rightSide++; // shift to only right
            mini = min(mini,nums[rightSide]);
        }
        
        ans = max(ans,mini*(rightSide-leftSide + 1));  // calculate the answer for each size and store the maximum answer
    }
    return ans;
}
};