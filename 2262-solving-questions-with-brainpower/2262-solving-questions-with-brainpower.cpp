class Solution {
public:
    // vector< long long > dp;
    // long long f(vector<vector<int>> &arr, long long i){
    //     if(i > arr.size() - 1) return 0;
    //     if(dp[i] != -1) return dp[i];

    //     long long sum1 = arr[i][0] + f(arr, i + arr[i][1] + 1);
    //     long long sum2 = f(arr, i+1);

    //     return dp[i] = max(sum1, sum2);
    // }
    long long mostPoints(vector<vector<int>>& questions) {
        // long long n = questions.size();
        // dp.resize(n+2, -1);
        // return f(questions, 0);

        long long n = questions.size();
        vector< long long > dp(n, 0);
        dp[n-1] = questions[n-1][0];

        for(long long i = n - 2; i >= 0; i--){
            long long sum1 = questions[i][0];
            long long nextIdx = i + questions[i][1] + 1;
            long long sum2 = dp[i+1];

            if(nextIdx < n){
                sum1 += dp[nextIdx];
            }

            dp[i] = max(sum1, sum2);

        }

        return dp[0];
    }
};