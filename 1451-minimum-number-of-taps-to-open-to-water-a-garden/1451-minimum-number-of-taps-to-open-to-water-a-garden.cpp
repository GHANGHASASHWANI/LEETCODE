class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector< int > dp(n+1 , 10000);

        dp[0] = 0;

        for(int i = 0; i < dp.size(); i++){
            int start = max(0, i- ranges[i]);
            int end = min(n, i + ranges[i]);

            for(int j = start; j <= end ; j++){
                dp[end] = min(dp[end], dp[j] +1);
            }
        }
        return dp[n] == 10000 ? -1: dp[n];
    }
};