/*  TLE solution
class Solution {
public:
    
    bool rec(vector<int> &gas, vector<int> &cost, int curr, int end, int currGas){
        cout<<"H "<<curr<<" ";
        int n = gas.size();  // size of the travel length
        currGas += gas[curr];  // adding the gas which prodive at that location by gas container
        curr = curr%n; // checking for overloading   4+1 --> 0 circular indexing
        end = end%n;  // circular indexing
        if(currGas >= cost[curr]){ // if currGas which we have right now is enough for moving to the next then we have to check more.
            if((curr+1)%n == end) return true;  // if we are able to move to next index and next index is out last index then return true
            return rec(gas, cost, (curr+1)%n, end, currGas-cost[curr]);  // calling for next index
        }
        return false;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        cout<<gas[0]<<" "<<cost[0]<<endl;
        int n = gas.size();  // size of the travel length
        for(int i = 0;i<gas.size();i++){ // traverse each index for find where is my ans
            if(gas[i] >= cost[i]){ // checking if it possible to move to next index from i or not
                if(rec(gas, cost, (i+1)%n, i,gas[i]-cost[i])) return i; // if it travel back to the index then return the index
                // rec call for next index and currGas = gas[i]-cost[i] initially
            }
        }
        return -1; // if it not travel back to the index then return the -1
    }
};
*/


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalCost = 0;
        int totalGas = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            totalCost += cost[i];
            totalGas += gas[i];
        }
        if(totalCost > totalGas)
            return -1;

        int startIndex=0, curFuel = 0;

        for(int i=0;i<n;i++){
            if(curFuel < 0){
                curFuel = 0;
                startIndex = i;
            }

            curFuel += (gas[i]-cost[i]);
        }
        return startIndex;
    }
};