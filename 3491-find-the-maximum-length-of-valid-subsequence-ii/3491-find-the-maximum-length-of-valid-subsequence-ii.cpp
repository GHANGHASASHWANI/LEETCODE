class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int> (k, 0));
        int maxLen = 0;
        for (auto num : nums) {
            num %= k;
            for (int prev = 0; prev < k; prev++) {
                dp[num][prev] = dp[prev][num] + 1;
                maxLen = max(maxLen, dp[num][prev]);
            }
        }
        return maxLen;
    }
};