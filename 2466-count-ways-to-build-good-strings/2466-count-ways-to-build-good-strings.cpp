class Solution {
public:
    int mod  = 1000000007;
    const int sz = 200005;
    const int lef = 100005;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> arraydp(sz);
        set<int> s ;
        for(int i =0; i< 10 ; i++) s.insert(i);
        arraydp[0] = 1;
        for(int i = 0; i < lef; i++){
            arraydp[i + zero] = arraydp[i + zero] % mod;
            arraydp[i + zero] += arraydp[i];
            arraydp[i + one] = arraydp[i + one]%mod;
           arraydp[i + one] += arraydp[i];
        }
        long long ansout = 0;
        while(low <= high){
            ansout = (ansout + arraydp[low])%mod;
            low++;
        }
        return ansout;
    }
};
