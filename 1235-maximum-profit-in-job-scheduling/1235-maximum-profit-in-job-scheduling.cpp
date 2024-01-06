class Solution {
public:
    int getNextIndex(const vector<vector<int>>& jobs, int start, int end, int target) {
        int left = start, right = jobs.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (jobs[mid][0] < end) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        for (int index = n - 1; index >= 0; index--) {
            int next = getNextIndex(jobs, index + 1, jobs[index][1], n);
            int include = jobs[index][2] + dp[next];
            int exclude = dp[index + 1];
            dp[index] = max(include, exclude);
        }

        return dp[0];
    }
};