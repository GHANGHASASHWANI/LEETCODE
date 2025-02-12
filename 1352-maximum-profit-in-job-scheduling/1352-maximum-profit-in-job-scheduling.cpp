class Solution {
public:
    int findNextJob(vector<tuple<int, int, int>>& interval, int index) {
        int low = index + 1, high = interval.size() - 1, ans = interval.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (get<0>(interval[mid]) >= get<1>(interval[index])) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> dp;
    int solve(int i, vector<tuple<int, int, int>>& interval) {
        if (i == interval.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int pick = INT_MIN;
        int nextIndex = findNextJob(interval, i);

        pick = get<2>(interval[i]) + solve(nextIndex, interval);

        int nonpick = solve(i + 1, interval);

        return dp[i] = max(pick, nonpick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        dp.clear();
        int maxi = *max_element(endTime.begin(), endTime.end());
        vector<tuple<int, int, int>> interval;

        for (int i = 0; i < startTime.size(); i++) {
            interval.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(interval.begin(), interval.end());

        dp.resize(startTime.size() + 1, -1);
        return solve(0, interval);
    }
};