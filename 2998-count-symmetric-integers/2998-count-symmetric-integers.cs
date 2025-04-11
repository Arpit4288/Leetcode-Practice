public class Solution {

    public bool IsSem(int n){
        string s = Convert.ToString(n);
        int l = s.Length;
        if(l % 2 != 0) return false;

        int sum = 0;
        int i = 0;
        while(i < l/2){
            sum +=  (n % 10);
            n /= 10;
            i++;
        }
        while(i < l){
            sum -= (n % 10);
            n /= 10;
            i++;
        }

        return sum == 0;
    }

    // public int CountDig(int n){

    // }

    public int CountSymmetricIntegers(int low, int high) {
        int ans = 0;

        for(int i = low; i <= high; i++){
            if(IsSem(i)) ans++;

        }
        return ans;
    }
}