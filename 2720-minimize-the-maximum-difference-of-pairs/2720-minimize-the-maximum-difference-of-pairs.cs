public class Solution {
    public int MinimizeMax(int[] nums, int p) {
        Array.Sort(nums);

        int low =0;
        int high = nums[^1] - nums[0];


   while(low < high){
    int mid = (high + low)/2;
       if(CanForm(nums,p,mid)){
        high = mid;

       } else{
        low = mid+1;
          }
       }
   return low;
    }

 private bool CanForm(int[] nums, int p, int maxDiff){
      int count = 0;
      int i = 0;

    while(i < nums.Length -1){
    if(nums[i+1] - nums[i] <= maxDiff){
        count++;
        i+=2;
    }else{
        i++;
         }
      }

   return count  >= p;

    }
}