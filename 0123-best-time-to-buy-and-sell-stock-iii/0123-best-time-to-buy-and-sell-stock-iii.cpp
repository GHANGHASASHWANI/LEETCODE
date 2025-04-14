class Solution {
private:
    int calculateProfit(int idx, int buy, int cap, vector< int> & prices, vector<vector<vector< int >>> &dp){
        if(idx >= prices.size()) return 0;
        if(cap <= 0) return 0;

        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

        int profit = 0;
        if(buy){
            int buyStock = calculateProfit(idx + 1, ! buy, cap, prices, dp) - prices[idx];
            int notBuyStock = calculateProfit(idx + 1, buy, cap, prices, dp);

            profit = max(buyStock, notBuyStock);
        }else{
            int sellStock = prices[idx] + calculateProfit(idx + 1, ! buy, cap - 1, prices, dp);
            int notSellStock = calculateProfit(idx + 1, buy, cap, prices, dp);
            
            profit = max(sellStock, notSellStock);
        }
        return dp[idx][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        // int len = prices.size();

        // vector<vector<vector< int >>> dp(len +1, vector<vector< int >> (2, vector< int> (3, -1)));

        // return calculateProfit(0, 1, 2, prices, dp);

        int len = prices.size();
        vector<vector<vector< int >>> dp(len+1, vector<vector< int >> (2, vector<int> (3, 0)));

        vector<vector< int >> curr(2, vector<int> (3, 0)), ahead(2, vector<int> (3, 0));

        for(int i = len - 1; i >= 0; i--){
            for(int j = 0; j <= 1; j++){
                for(int k = 1; k <= 2; k++){
                    int profit = 0;
                    if(j){
                        int buyStock = ahead[!j][k] - prices[i];
                        int notBuyStock = ahead[j][k];
                        profit = max(buyStock, notBuyStock);
                    }else{
                        int sellStock = ahead[!j][k - 1] + prices[i];
                        int notSellStock = ahead[j][k];
                        profit = max(sellStock, notSellStock);
                    }
                    curr[j][k] = profit;
                }
                ahead = curr;
            }
        }

        return curr[1][2];
    }
};