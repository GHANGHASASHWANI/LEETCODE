class Solution {
public:
    vector< long long > dp;
    long long f(vector<vector<int>> &arr, long long i){
        if(i > arr.size() - 1) return 0;
        if(dp[i] != -1) return dp[i];

        long long sum1 = arr[i][0] + f(arr, i + arr[i][1] + 1);
        long long sum2 = f(arr, i+1);

        return dp[i] = max(sum1, sum2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        dp.resize(n+2, -1);
        return f(questions, 0);
    }
};