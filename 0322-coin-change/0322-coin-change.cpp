class Solution {
public:

    int minimizeCoins(vector<int> &coins, int amount, vector<long long> &dp){
        if(amount == 0) return 0;
        if(amount < 0) return 1e8;
        int minimum = 1e8;
        if(dp[amount] != -1) return dp[amount];

        for(int startIndex = 0; startIndex < coins.size(); startIndex++){
            if(amount - coins[startIndex] < 0) continue;
            minimum = min(minimum, minimizeCoins(coins, amount - coins[startIndex], dp));
        }

        return dp[amount] = 1 + minimum;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector< long long > dp(amount + 1, -1);
        long long answer = minimizeCoins(coins, amount, dp);
        return answer != 1e8 + 1 ? answer : -1;
    }
};