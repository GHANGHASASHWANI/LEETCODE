class Solution {
public:
    vector< int > dp;
    int fn(int steps, int n){
        if(steps == n){
            return 1;
        }
        if(steps > n){
            return 0;
        }
        if(dp[steps] != -1) return dp[steps];

        int step1 = fn(steps + 1, n);
        int step2 = fn(steps + 2, n);

        return dp[steps] = step1 + step2;
    }
    int climbStairs(int n) {
        int steps =  0;
        dp.clear();
        dp.resize(n+1, -1);
        return fn(steps, n);
    }
};