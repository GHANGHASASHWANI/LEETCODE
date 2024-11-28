class Solution {
public:
    int dp[1005][1005][2];

    int profit(vector<int> &prices, int i, int k, int on){
        if(i == prices.size()) return 0;

        if(dp[i][k][on] != -1) return dp[i][k][on];

        int res = INT_MIN;
        res = profit(prices, i+1, k, on);

        if(on){
            res = max(res, prices[i] + profit(prices, i+1, k-1, false));
        }else{
            if(k>0) res = max(res, profit(prices, i+1, k, true) - prices[i]);
        }
        return dp[i][k][on] = res;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return profit(prices, 0, k, false);
    }
};