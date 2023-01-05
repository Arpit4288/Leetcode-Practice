class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int endpoint = points[0][1]; // initially last point is last ending point of smallest balloon (i.e. 6 for eg 1)
        int ans = 1;  // minimum 1 arrow neede for first balloon
        for(auto point : points) {
            if(point[0] > endpoint) { // if starting point of a balloon > we have covered so far then we need one more arrow
                ans++;
                endpoint = point[1];
            }
            endpoint = min(point[1],endpoint);  // if starting point of a balloon > we have covered so far then this baloon can brust from that range don't worry for this
        }
        return ans;
    }
};