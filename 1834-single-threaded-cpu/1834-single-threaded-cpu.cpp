/*  TLE Solution
class myComparator {
  public:
    bool operator() (const pair<int,int> &p1, const pair<int,int> &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
    }
};

class Solution {
public:    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int maxTime = 0;
        unordered_map<int,vector<pair<int,int> >> mp;
        for(int i = 0;i<tasks.size();i++){
            maxTime = max(maxTime, tasks[i][0]);
            mp[tasks[i][0]].emplace_back(make_pair(tasks[i][1], i));
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        vector<int> ans;

        int prevTime = 1, currTime = 1;
        while(currTime <= maxTime || !pq.empty()){
            for(int i = prevTime; i<= currTime;i++){
                if(mp.find(i) != mp.end()){
                    vector<pair<int,int>> arr = mp[i];
                    for(auto it : arr) pq.push(it);
                }
            }
            if(!pq.empty()){
                pair<int,int> pr = pq.top();
                pq.pop();
                prevTime = currTime+1;
                currTime += pr.first;
                ans.emplace_back(pr.second);

            }
            else{
                prevTime++;
                currTime++;
            }
        }
        
        
        return ans;
    }
}; 
*/






class Solution 
{
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        int n = tasks.size(), i = 0;
        vector<vector<int>> arr; // take a new array and store the index as well from original array
        for (int i = 0; i < n; i++)
            arr.push_back({tasks[i][0], tasks[i][1], i});

        sort(arr.begin(), arr.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;  // min heap

        vector<int> ans;
        int endtime = arr[i][0];

        while (i < n)
        {
            if (!pq.empty())
            {
                endtime += pq.top()[0];
                ans.push_back(pq.top()[1]);
                pq.pop();
            }
            while (i < n and arr[i][0] <= endtime)
            {
                pq.push({arr[i][1], arr[i][2], arr[i][0]});
                i++;
            }
            if (i < n and endtime < arr[i][0] and pq.empty())
                endtime = arr[i][0];
        }

        while (!pq.empty())
            ans.push_back(pq.top()[1]), pq.pop();

        return ans;
    }
};