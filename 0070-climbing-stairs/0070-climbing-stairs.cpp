class Solution {
public:
    int arr[45] = {-1};
    int climbStairs(int n) {
        if(n <= 3) return n;
        int n1, n2;
        if(arr[n-1] == 0){
            n1 = climbStairs(n-1);
            // cout<<"n1 is : "<<n1<<"  ";
            arr[n-1] = n1;
        }
        else n1 = arr[n-1];
        if(arr[n-2] == 0){
            n2 = climbStairs(n-2);
            arr[n-2] = n2;
        }
        else n2 = arr[n-2];
        return arr[n-1] + arr[n-2];
    }
};