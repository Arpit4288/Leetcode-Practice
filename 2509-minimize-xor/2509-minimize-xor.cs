public class Solution {
    public int MinimizeXor(int num1, int num2) {
        int num3 = num1;
        int number = 0;
        int count1 = 0;
        StringBuilder sb = new StringBuilder();
        while(num3!=0){
            number++;
            sb.Insert(0,(num3&1).ToString());
            num3 = num3 >> 1;
        }
        while(num2!=0){
            if((num2 & 1) == 1){
                count1++;
            }
            num2 = num2>>1;
        }
        int res = 0;
        if(count1>=number){
            return (int)Math.Pow(2,(double)count1)-1;
        }else{
            int[] array = new int[number];
            int pow = 1 << (number-1);
            for(int i=0;i<number;i++){
                if(count1==0){
                    break;
                }
                if(sb[i]=='1'){
                    count1--;
                    res+=pow;
                }
                pow=pow>>1;
            }
            while(count1>0){
                pow = 1;
                for(int i=sb.Length-1;i>=0;i--){
                    if(sb[i] == '0'){
                        sb[i] = '1';
                        count1--;
                        res+=pow;
                        break;
                    }
                    pow = pow<<1;
                }
            }
        }
        return res;
    }
}