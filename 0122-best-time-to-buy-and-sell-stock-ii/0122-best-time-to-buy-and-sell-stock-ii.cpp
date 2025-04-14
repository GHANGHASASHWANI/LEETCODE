class Solution {
private:
    int calculateProfit(int idx, bool buy, vector< int> &prices, vector<vector< int >> &dp){
        if(idx >= prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        if(buy){
            int buyStock = calculateProfit(idx + 1, ! buy, prices, dp) - prices[idx];
            int notBuyStock = calculateProfit(idx + 1, buy, prices, dp);
            profit = max(buyStock, notBuyStock);
        }else{
            int sellStock = prices[idx] + calculateProfit(idx + 1, ! buy, prices, dp);
            int notSellStock = calculateProfit(idx + 1, buy, prices, dp);
            profit = max(sellStock, notSellStock);
        }

        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        // int len = prices.size();
        // vector<vector<int>> dp(len, vector< int > (2, -1));
        // return calculateProfit(0, true, prices, dp);

        int len = prices.size();
        vector<vector< int >> dp(len + 1, vector< int > (2, 0));

        for(int idx = len - 1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    int buyStock = dp[idx + 1][!buy] - prices[idx];
                    int notBuyStock = dp[idx + 1][buy];
                    profit = max(buyStock, notBuyStock);
                }else{
                    int sellStock = dp[idx + 1][!buy] + prices[idx];
                    int notSellStock = dp[idx + 1][buy];
                    profit = max(sellStock, notSellStock);
                }
                dp[idx][buy] = profit;
            }
        }

        return dp[0][1];
    }
};