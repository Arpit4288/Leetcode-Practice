public class Solution {
    public int findSum(int n){
        int sum = 0;
        while(n > 9){
            sum += n%10;
            n = n/10;
        }
        sum += n;
        return sum;
        
    }


    public int MaximumSum(int[] nums) {
        int max = -1;
        Dictionary<int, int> collection = new Dictionary<int, int>();
        for(int i = 0; i < nums.Length; i++){
            int sum = findSum(nums[i]);
            // Console.Write("Sum is : " + sum);
            if(collection.ContainsKey(sum)){
                max = Math.Max(max, nums[i] + collection[sum]);
                // Console.Write(" if > max is now : " + max);
                collection[sum] = Math.Max(nums[i], collection[sum]);
            }
            else {
                collection.Add(sum, nums[i]);
                // Console.Write(" else > max is still : " + max);
            }
            Console.WriteLine();
        }
        return max;
    }
}