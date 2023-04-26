class Solution {
public:
    
    int sumDigits(int n){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
    int addDigits(int num) {
        while(num != 0 && num > 9){
            num = sumDigits(num);
        }
        return num;
    }
};