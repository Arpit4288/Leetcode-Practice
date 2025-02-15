public class Solution {
    public int RemoveDuplicates(int[] arr) {
        if(arr.Length == 1) return 1;
        int i = 0, j = 1;
        while(j < arr.Length){
            if(arr[i] != arr[j]){
                (arr[i + 1], arr[j]) = (arr[j], arr[i + 1]);
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return  i+1;
    }
}
/*
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        int prev = 0, curr = 1;
        while(curr < arr.size()){
            if(arr[curr] != arr[prev]){
                swap(arr[curr], arr[prev+1]);
                curr++; prev++;
            }
            else curr++;
        }
        return prev+1;
    }
};
*/