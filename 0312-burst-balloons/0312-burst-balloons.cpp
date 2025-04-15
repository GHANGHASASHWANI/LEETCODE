class Solution {
private:
    int brust(int start, int end, const vector< int > &nums, vector<vector< int >> &dp){
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];

        long long maxBrust = INT_MIN;

        for(int idx = start; idx <= end; idx++){
            long long partition1 = brust(start, idx - 1, nums, dp);
            long long partition2 = brust(idx + 1, end, nums, dp);
            long long score = nums[start - 1] * nums[idx] * nums[end + 1];

            maxBrust = max(maxBrust, partition1 + partition2 + score);
        }

        return dp[start][end] = maxBrust;
    }
public:
    int maxCoins(vector<int>& nums) {
        // nums.push_back(1);
        // nums.insert(nums.begin(), 1);
        // int n = nums.size();
        // vector<vector< int >> dp(n, vector< int >(n, -1));
        // return brust(1, n - 2, nums, dp);

        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector< int >> dp(n, vector< int >(n, 0));

        for(int start = n - 2; start >= 1; start--){
            for(int end = 1; end <= n - 2; end++){
                if(start > end) continue;

                int maxBrust = INT_MIN;

                for(int idx = start; idx <= end; idx++){
                    int partition1 = dp[start][idx-1];
                    int partition2 = dp[idx+1][end];
                    int score = nums[start - 1] * nums[idx]* nums[end + 1];

                    maxBrust = max(maxBrust, score + partition1 + partition2);
                }
                dp[start][end] = maxBrust;
            }
        }

        return dp[1][n - 2];
    }
};