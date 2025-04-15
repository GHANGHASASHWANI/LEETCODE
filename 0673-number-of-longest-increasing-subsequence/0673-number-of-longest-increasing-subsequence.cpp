class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();

        vector< int > dp(len, 1);
        vector< int > count(len, 1);

        int maxLen = 1;

        for(int i = 0; i < len; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if( nums[i] > nums[j] && dp[i] == 1 + dp[j]){
                    count[i] += count[j];
                }
            }
            if(maxLen < dp[i]){
                maxLen = dp[i];
            }
        }

        int maxFreq = 0;

        for(int i =0; i < len; i++){
            if(dp[i] == maxLen) maxFreq += count[i];
        }

        return maxFreq;
    }
};