class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> timeframe;
        for(auto time: timePoints){
            int hours = stoi(time.substr(0,2));
            int minutes = stoi(time.substr(3,2));
            int total = hours * 60 + minutes;
            timeframe.push_back(total);
        }
        int min_diff = INT_MAX;

        sort(timeframe.begin(), timeframe.end());

        int s = 0, e = 1;
        // Check min difference between every consecutive index
        while(e < timePoints.size()){
            int diff = timeframe[e] - timeframe[s];
            if(diff >= 0)
                min_diff = min(min_diff, diff);

            e ++;
            s++;
        }
        // Check the min difference between last and first index of sorted times.
        // Equivalent to going upto the 23:59 from the last index and then starting from 00:00 to the first
        int diff2 = (1440 - timeframe[s]) + timeframe[0];
        if(diff2 >= 0)
            min_diff = min(min_diff, diff2);

        return min_diff;
    }
};