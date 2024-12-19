class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n=arr.size();
        
        int ans=0;
        for(int i=0;i<n;)
        {
            if(i==arr[i])
            {
                ans++;
                i++;
            }
            else
            {
                int maxx=arr[i];
                for(int j=i+1 ; j<= maxx ;j++)
                {
                    maxx=max(maxx , arr[j]);
                    if(j==maxx)
                    {
                        ans++;
                        i=j+1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};