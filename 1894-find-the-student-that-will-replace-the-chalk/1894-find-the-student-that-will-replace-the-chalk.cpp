class Solution {
public:
    int chalkReplacer(vector<int>& arr, int k) {
        long long int sum = 0;
        sum = accumulate(arr.begin(), arr.end(), sum);
        k %= sum;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] <= k) k -= arr[i];
            else return i;
        }
        return -1;
    }
};