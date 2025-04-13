class Solution {
private:
    // vector<unordered_map<int, int>> dp;
    // int fn(int idx, int diff, vector<int> &nums){
    //     if(idx >= nums.size()) return 0;
    //     if(dp[idx].count(diff)) return dp[idx][diff];
    //     int len = 0;

    //     for(int i = idx + 1; i < nums.size(); i++){
    //         int ndiff = nums[i] - nums[idx];
    //         if(ndiff == diff){
    //             len = max(len, 1 + fn(i, diff, nums));
    //         }
    //     }
    //     return dp[idx][diff] = len;
    // }
public:
    int longestArithSeqLength(vector<int>& nums) {
        // int n = nums.size();
        // dp.clear();
        // dp.resize(nums.size() + 1);
        // int res = 0;
        // for(int i =0; i < nums.size(); i++){
        //     for(int j = i+1; j < nums.size(); j++){
        //         int diff = nums[j] - nums[i];
        //         res = max(res, 2 + fn(j, diff, nums));
        //     }
        // }
        // return res;
        int n = nums.size();
        vector<vector< int >> dp(n, vector<int> (1001, 0));

        int result = 0;

        for(int i =0; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = nums[j] - nums[i] + 500;
                dp[i][diff] = dp[j][diff]>0 ? dp[j][diff]+1 : 2;

                result = max(result, dp[i][diff]);
            }
        }
        return result;
    }
};