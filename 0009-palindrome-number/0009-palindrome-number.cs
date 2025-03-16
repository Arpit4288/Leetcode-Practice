public class Solution {
    public bool IsPalindrome(int n) {
        int orig = n;
        if(n < 0 || (n >= int.MaxValue || n <= int.MinValue)) return false;
        int rev = 0;
        while(n > 9){
            int x = n % 10;
            rev = rev * 10 + x;
            n = n / 10;
        }
        rev = rev * 10 + n;
        // Console.WriteLine(rev);
        return orig == rev;
    }
}