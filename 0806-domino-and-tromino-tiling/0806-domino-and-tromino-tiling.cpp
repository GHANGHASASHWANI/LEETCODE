class Solution {
public:
// vector<int> dp;
int mod = 1e9 + 7;
//     int fn(int n){
//         if(n <= 0) return 0;
//         if(n == 1) return 1;
//         if(n == 2) return 2;
//         if(n == 3) return 5;

//         if(dp[n] != -1) return dp[n];

//         return dp[n] = (2*fn(n-1)%mod + fn(n-3)%mod)%mod;
//     }
    int numTilings(int n) { 
        // dp.clear();
        // dp.resize(n+1, -1);
        // return fn(n);
        if(n <= 2) return n;

        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for(int i = 4; i <= n; i++){
            dp[i] =(2*dp[i-1]%mod + dp[i-3])%mod;
            // cout<<dp[i]<<endl;
        }
        return dp[n];
    }
};