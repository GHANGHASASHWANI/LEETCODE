class Solution {
public:
    vector< int> dp;
    int fn(vector< int> &nums, int i){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + fn(nums, i+2);
        int nonPick = fn(nums, i+1);

        return dp[i] = max(pick, nonPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.clear();
        dp.resize(n+1, -1);
        return fn(nums, 0);
    }
};