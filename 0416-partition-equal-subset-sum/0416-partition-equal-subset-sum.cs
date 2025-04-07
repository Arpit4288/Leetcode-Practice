public class Solution {

    
    //true = 0, false = 1, empty = -1
    public int findPossiblePartition(int[] nums, int sum, int n, int[,] dp)
    {
        
        if(sum == 0)
            return 0;

        if(n == 0)
            return 1;

        if(dp[n,sum] != -1)
             return dp[n,sum];

        if(nums[n-1] > sum)
        {
            //exclude
            return dp[n,sum] = findPossiblePartition(nums,sum,n-1,dp);
        }
        else if(findPossiblePartition(nums,sum,n-1,dp) != 1 || findPossiblePartition(nums,sum-nums[n-1], n-1,dp) != 1)
        {
            return dp[n,sum] = 0;
        }

        return dp[n,sum] = 1;
    }

    public bool CanPartition(int[] nums) {

        int sum =0;
        foreach(int elem in nums)
        {
            sum+=elem;
        }

        if(sum % 2 != 0)
            return false;

        sum = sum/2;
        int n = nums.Length;
        int[,] dp = new int[n+1,sum+1];

        //fill dp with -1
        for(int i=0; i<=nums.Length; i++)
        {
            for(int j=0;j<=sum;j++)
            {
                dp[i,j] = -1;
            }
        }

        int res = findPossiblePartition(nums,sum, nums.Length,dp);
        if(res == 0)
            return true;

        return false;
    }
}