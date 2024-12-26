class Solution {
public:
    vector<vector<int>> dp;
    int targetSum(vector<int> &nums, int target, int sum, int index){
        if(index == nums.size() && sum == target) return 1;
        if(index >= nums.size()) return 0;

        if(dp[1000 + sum][index] != -1) return dp[1000 + sum][index];

        int plus = targetSum(nums, target, sum + nums[index], index + 1);
        int minus = targetSum(nums, target, sum - nums[index], index + 1);

        return dp[1000 + sum][index] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        dp.resize(2005, vector<int> (25, -1));
        return targetSum(nums, target, 0, 0);
    }
};