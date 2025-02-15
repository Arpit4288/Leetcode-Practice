public class Solution {
    public int FindKthLargest(int[] arr, int k) {
        PriorityQueue<int, int> q = new PriorityQueue<int, int>();
        for(int i = 0; i < arr.Length; i++){
            q.Enqueue(arr[i], -arr[i]);
        }
        int res = 0;
        while(k > 0){
            res = q.Dequeue();
            k--;
        }
        return res;
    }
}