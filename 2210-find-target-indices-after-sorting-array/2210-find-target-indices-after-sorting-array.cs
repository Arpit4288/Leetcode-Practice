public class Solution {
    public IList<int> TargetIndices(int[] arr, int target) {
        int smallerCount = 0, targetCount = 0;

        for(int i = 0; i < arr.Length; i++){
            if(arr[i] == target) targetCount++;
            else if(arr[i] < target) smallerCount++;
        }
        if(target == 0) return new List<int>();
        return Enumerable.Range(smallerCount, targetCount).ToList();
    }
}