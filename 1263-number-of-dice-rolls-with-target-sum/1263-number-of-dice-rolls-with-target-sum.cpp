class Solution {
public:
    vector<vector<int>> dp;
    int possibleRolls(int n, int k, int target) {
        int mod = 1e9 + 7;
        if (n == 0 && target == 0)
            return 1;
        if (n == 0)
            return 0;

        int sum = 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        for (int idx = 1; idx <= k; idx++) {
            if (target - idx < 0)
                break;
            sum = ((sum) % mod + (possibleRolls(n - 1, k, target - idx)) % mod) %
                  mod;
        }
        return dp[n][target] = sum % mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35, vector<int>(1005, -1));
        return possibleRolls(n, k, target);
    }
};