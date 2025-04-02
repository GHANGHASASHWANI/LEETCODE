class Solution {
public:
    vector< vector<int>> dp;
    int fn(bool buy, vector<int> &prices, int day){
        if(day >= prices.size()) return 0;
        if(dp[day][buy] != -1) return dp[day][buy];
        int profit = 0;
        if(buy){
            int take = fn(false, prices, day + 1) - prices[day];
            int notTake = fn(true, prices, day + 1);

            profit = max({profit, take, notTake});
        }else{
            int sell = prices[day] + fn(true, prices, day + 2);
            int notSell = fn(false, prices, day + 1);

            profit = max({profit, sell, notSell});
        }

        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.clear();
        dp.resize(n, vector<int> (2, -1));
        return fn(true, prices, 0);
    }
};