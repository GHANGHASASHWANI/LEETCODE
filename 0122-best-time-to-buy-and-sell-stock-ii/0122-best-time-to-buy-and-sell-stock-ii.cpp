class Solution {
public:
 int dp[100005][2];

    int profit(vector<int> &prices, int i,  int on){
        if(i == prices.size()) return 0;

        if(dp[i][on] != -1) return dp[i][on];

        int res = INT_MIN;
        res = profit(prices, i+1, on);

        if(on){
            res = max(res, prices[i] + profit(prices, i+1, false));
        }else{
             res = max(res, profit(prices, i, true) - prices[i]);
        }
        return dp[i][on] = res;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return profit(prices, 0, false);
    }
};