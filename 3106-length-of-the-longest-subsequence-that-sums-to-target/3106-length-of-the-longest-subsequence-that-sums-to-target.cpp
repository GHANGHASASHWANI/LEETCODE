class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;

        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                if (dp[j - num] != INT_MIN) {
                    dp[j] = max(dp[j], 1 + dp[j - num]);
                }
            }
        }

        return dp[target] == INT_MIN ? -1 : dp[target];
    }
};
