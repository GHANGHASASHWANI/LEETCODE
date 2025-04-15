class Solution {
public:
    vector<vector<int>> dp;
    int minimumCost(int i, int j, vector<int>& cuts) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            int steps = cuts[j + 1] - cuts[i - 1] +
                        minimumCost(i, k - 1, cuts) +
                        minimumCost(k + 1, j, cuts);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        dp.clear();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        dp.resize(n + 5, vector<int>(n + 5, -1));
        return minimumCost(1, cuts.size() - 2, cuts);
    }
};