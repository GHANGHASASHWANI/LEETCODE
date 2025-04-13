
class Solution {
private:
    vector<vector<int>> dp;
    int n;
    int fn(int idx, int k, vector<vector<int>>& arr) {
        if (idx >= n || k <= 0)
            return 0;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int take = 0, notTake = 0;
        int j = upper_bound(
            arr.begin(),
            arr.end(),
            arr[idx][1],
            [](int value, const vector<int>& event) {
                return value < event[0]; // Only compare with start time
            }
        ) - arr.begin();

        take = arr[idx][2] + fn(j, k - 1, arr);
        notTake = fn(idx + 1, k, arr);

        return dp[idx][k] = max(take, notTake);
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        dp.clear();
        n = events.size();
        dp.resize(n + 1, vector<int>(k + 1, -1));
        return fn(0, k, events);
    }
};