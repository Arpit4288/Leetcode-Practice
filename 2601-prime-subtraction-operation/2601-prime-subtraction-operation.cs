public class Solution {
    public bool PrimeSubOperation(int[] nums) {
        int[] arr = new int[1001];
        for(int i=2; i<1001; i++) {
            int multiple = 2;
            while(i * multiple <= 1000) {
                arr[i * multiple] = -1;
                multiple++;
            }
        }

        List<int> primes = new();
        for(int i=2; i<1001; i++)
            if(arr[i] == 0)
                primes.Add(i);

        nums[0] -= getSubtraction(nums[0], primes, 0);
        
        for(int i=1; i<nums.Length;i++) {
            if(nums[i] <= nums[i-1])
                return false;
            int sub = getSubtraction(nums[i], primes, nums[i-1]);
            if(nums[i] - sub > nums[i-1])
                nums[i] -= sub;
        }

        return true;
    }

    private int getSubtraction(int num, List<int> primes, int min) {
        int max = 0;
        foreach(var prime in primes) {
            if(prime < num && (num - prime > min))
                max = Math.Max(prime, max);
        }
        return max;
    }
}