class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int hibit = 0, lobit = 0, temp = low;
        for(lobit=0; temp > 0; lobit++) temp /= 10;
        temp = high;
        for(hibit=0; temp > 0; hibit++) temp /= 10;
        long long int num = 123456789;
        vector<int> res;
        for(int i=lobit; i<=hibit; i++){
            long long int tail = 1, trim = 1;
            for(int k=0; k<9-i; k++) tail *= 10;
            for(int k=0; k<i; k++) trim *= 10;
            for(int j=0; j<=9-i; j++){
                long long int n = (num / tail) % trim;
                if(n >= low && n <= high) res.push_back(n);
                else if(n > high) return res;
                tail /= 10;
            }
        }
        return res;
    }
};