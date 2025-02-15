public class Solution {
    public bool CanBeEqual(int[] target, int[] arr) {
        int[] store = new int[1001];
        for(int i = 0; i < target.Length; i++) store[target[i]]++;
        for(int i = 0; i < arr.Length; i++) store[arr[i]]--;
        for(int i = 0; i < store.Length; i++){
            if(store[i] != 0) return false;
        }
        return true;
    }
}