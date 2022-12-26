class Solution {
public:
    
    bool isreach(vector<int> &arr, int curr, int n, vector<int> &dp){
        if(curr >= n-1) return true;
        if(dp[curr] != -1) return dp[curr] == 0 ? false : true;
        if(arr[curr] == 0){
            dp[curr] = 0;
            return false;
        }
        
        bool check = false;
        for(int i = 1;i<=arr[curr];i++){
            if(isreach(arr, curr+i, n, dp) == true){
                check = true;
                dp[curr] = 1;
                break;
            }
            else dp[curr] = 0;
        }
        dp[curr] = check == false ? 0 : 1;
        return check;
    }
    
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return true;
        vector<int> dp(n, -1);
        return isreach(arr, 0, n, dp);
    }
};