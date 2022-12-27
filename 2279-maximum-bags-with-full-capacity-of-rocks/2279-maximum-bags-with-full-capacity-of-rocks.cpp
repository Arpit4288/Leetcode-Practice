class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int addrocs) {
        for(int i = 0;i<cap.size();i++) cap[i] = cap[i]-rocks[i];
        sort(cap.begin(), cap.end());
        int ans = 0;
        for(int i = 0;i<cap.size();i++){
            if(cap[i] == 0){
                ans++;
                continue;
            }
            if(cap[i] > addrocs){
                continue;
            }
            else{
                addrocs -= cap[i];
                cap[i] = 0;
                ans++;
            }
        }
        return ans;
        
    }
};