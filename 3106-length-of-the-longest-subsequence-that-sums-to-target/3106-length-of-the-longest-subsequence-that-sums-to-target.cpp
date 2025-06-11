class Solution {
private:
    int fn(int idx, int sum, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if (sum == target) return 0;
        if (idx >= nums.size() || (target - sum) < 0) return sum == target ? 0 : INT_MIN;
        

        if(dp[idx][sum] != -1) return dp[idx][sum];

        int pick =  1 + fn(idx + 1, sum + nums[idx], target, nums, dp);
        int nonPick = fn(idx + 1, sum, target, nums, dp);

        return dp[idx][sum] = max(pick, nonPick);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        // int total = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> dp(n+1, vector<int> (target + 1, -1));

        int ans = fn(0, 0, target, nums, dp);
        if (ans < -1) return -1;
        return ans;
    }
};