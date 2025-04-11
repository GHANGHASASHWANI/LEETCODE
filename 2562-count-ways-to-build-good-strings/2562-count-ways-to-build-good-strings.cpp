class Solution {
private:
    const int mod = 1e9 + 7;
    // vector< int > dp;
    // int fn(int len, int low, int high, int one, int zero){
    //     if(len > high) return 0;
    //     if(dp[len] != -1) return dp[len];
    //     int ans = 0;
    //     if(len >= low && len <= high) ans =  1;

    //     int addZero = fn(len + zero, low, high, one, zero) % mod;
    //     int addOne = fn(len + one, low, high, one, zero)% mod;

    //     return dp[len] =  ((ans + addZero) % mod + addOne) % mod;
    // }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // dp.clear();
        // dp.resize(high + 1, -1);
        // return fn(0, low, high, zero, one);
        vector< int > dp(high + 1, 0);

        for(int len = high; len >= 0; len--){
            int ans = 0;
            if(len >= low && len <= high) ans =  1;
            
            if(len + zero <= high) ans =( ans + dp[len + zero]) % mod;
            if(len + one <= high) ans = (ans + dp[len + one]) % mod;

            dp[len] =  ans;
        }
        return dp[0];
    }
};