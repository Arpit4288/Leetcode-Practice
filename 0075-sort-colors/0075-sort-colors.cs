public class Solution {
    public void SortColors(int[] arr) {
        int i = 0, j = 0, k = arr.Length - 1;
        while(j <= k){
            if(arr[j] == 0){
                (arr[i], arr[j]) = (arr[j], arr[i]);
                i++;
                j++; // everytime at i we are sure it array will have 1 only, so after swap we can increment j also
            }
            else if(arr[j] == 2){
                (arr[j], arr[k]) = (arr[k], arr[j]);
                k--;
            }
            else j++;
        }
    }
}