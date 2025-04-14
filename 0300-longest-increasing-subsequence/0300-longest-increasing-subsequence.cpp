class Solution {
private:
    // int longestLIS(int idx, int prev,const vector<int> &nums, vector<vector< int >> &dp){
    //     if(idx >= nums.size()) return 0;

    //     if(dp[idx][prev+1] != -1) return dp[idx][prev + 1];
        
    //     int notTakeIdx = longestLIS(idx + 1, prev, nums, dp);
    //     int takeIdx = 0;
    //     if(prev == -1 || nums[idx] > nums[prev]){
    //         takeIdx = 1 + longestLIS(idx + 1, idx, nums, dp);
    //     }

    //     return dp[idx][prev + 1] = max(takeIdx, notTakeIdx);
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        // const int len = nums.size();
        // vector<vector< int >> dp(len, vector<int> (len + 1, -1));
        // return longestLIS(0, -1, nums, dp);

        const int len = nums.size();
        vector<vector< int >> dp(len + 1, vector< int > (len + 2, 0));

        vector< int > curr(len + 2, 0), ahead(len + 2, 0);

        for(int i = len - 1; i >= 0; i--){
            for(int j = i - 1; j >= -1; j--){
                int notTake = ahead[j+1];
                int take = 0;
                if(j == -1 || nums[i] > nums[j]){
                    take = 1 + ahead[i+1];
                }
                curr[j + 1] = max(take, notTake);
            }
            ahead = curr;
        }
        return ahead[0];
    }
};