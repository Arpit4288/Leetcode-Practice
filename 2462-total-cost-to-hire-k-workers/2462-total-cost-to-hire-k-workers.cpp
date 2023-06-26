#define ll long long  
#define umii unordered_map<int,int> 
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        ll answer=0;
        priority_queue<int, vector<int>, greater<int> > prior1;
        priority_queue<int, vector<int>, greater<int> > prior2;
        int i=0;
        while(i<cand){
            prior1.push(costs[i]);
            i++;
        }
        int count=0;
        int j= costs.size()-1;
        if(cand > costs.size()- cand) cand= costs.size()- cand;
        
        while(count<cand){
            prior2.push(costs[j]);
            count++;
            j--;
        }
        
        while(k--){
            if(prior1.size()==0){
                answer+=prior2.top();
                prior2.pop();
                if(i<=j){
                   prior2.push(costs[j]);
                    j--;
                } 
                
            }
            else if(prior2.size()==0){
                answer+=prior1.top();
                prior1.pop();
                if(i<=j){
                    prior1.push(costs[i]);
                    i++;
                } 
            }
            else if(prior1.top()<=prior2.top()){
                answer+=prior1.top();
                prior1.pop();
                if(i<=j){
                    prior1.push(costs[i]);
                    i++;
                }
            }
            else{
                answer+=prior2.top();
                prior2.pop();
                if(i<=j){
                    prior2.push(costs[j]);
                    j--;
                } 
                
                
            }
        }
        return answer;
    }
};
