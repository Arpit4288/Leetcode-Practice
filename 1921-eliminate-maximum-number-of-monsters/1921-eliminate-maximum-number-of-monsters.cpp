class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // Intution
        // The idea in here is really very simple. We will find the time taken by each monster to reach us with the help of the formual time is equal to distance / speed. Given that we will sort it and continue the process till we found that two correspodning elements are equal if we found that the corresponding elements are equal then we will elimnate them.
        vector<double> current;
        int size = dist.size();
        for(int i = 0 ; i < size ; i++){
            double value = dist[i] * 1.0 / speed[i] * 1.0;
            current.push_back(value);
        }
        sort(current.begin(), current.end());
        int answer = 0;
        for(int i = 0 ; i < size ; i++){
            if(i != 0 and i >= current[i]) break;
            answer += 1;
        }
        return answer;
    }
};