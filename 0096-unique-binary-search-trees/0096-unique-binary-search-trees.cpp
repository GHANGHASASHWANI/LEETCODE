class Solution {
public:
    vector< int > dp;

    int totalWays(int n){
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;

        int sum = 0;
        if(dp[n] != -1) return dp[n];
        for(int k = 1; k <= n; k++){
            sum += totalWays(k - 1) * totalWays(n - k);
        }
        return dp[n] = sum;
    }
    int numTrees(int n) {
        dp.clear();
        dp.resize(20, -1);
        return totalWays(n);
    }
};