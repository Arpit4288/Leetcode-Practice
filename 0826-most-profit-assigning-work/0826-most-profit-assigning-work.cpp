class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++) vec[i]={difficulty[i],profit[i]};
        sort(vec.begin(),vec.end());
        for(int i=1;i<n;i++) vec[i].second=max(vec[i].second,vec[i-1].second);
        int cost=0;
        for(auto it:worker){
            int low=0,high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(vec[mid].first<=it) low=mid+1;
                else high=mid-1;
            }
            if(high>=0) cost+=vec[low-1].second;
        }
        return cost;
    }
};