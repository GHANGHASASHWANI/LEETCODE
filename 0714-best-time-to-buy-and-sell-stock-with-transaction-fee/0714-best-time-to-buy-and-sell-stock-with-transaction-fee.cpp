class Solution {
private:
    vector<vector<int>> dp;
    // int fn(bool buy, int i, vector<int> &prices, int fee){
    //     if(i >= prices.size()) return 0;
    //     if(dp[buy][i] != -1) return dp[buy][i];
    //     int sum1 = 0, sum2 = 0;
    //     if(buy){
    //         sum1 = fn(buy, i+1, prices, fee);
    //         sum2 = fn(!buy, i+1, prices, fee) - prices[i] - fee;
    //     }else{
    //         sum1 = fn(buy, i+1, prices, fee);
    //         sum2 = prices[i] + fn(!buy, i+1, prices, fee);
    //     }

    //     return dp[buy][i] = max(sum1, sum2);
    // }
public:
    int maxProfit(vector<int>& prices, int fee) {
        // dp.clear();
        // dp.resize(2, vector<int> (prices.size(), -1));
        // return fn(true, 0, prices, fee);

        dp.clear();
        dp.resize(2, vector<int> (prices.size()+1, 0));

        for(int i = prices.size()-1; i >= 0; i--){
            for(int buy = 1; buy >= 0; buy--){
                int sum1 = 0, sum2 = 0;
                if(buy){
                    sum1 = dp[buy][i+1];
                    sum2 = dp[!buy][ i+1] - prices[i] - fee;
                }else{
                    sum1 = dp[buy][i+1];
                    sum2 = prices[i] + dp[!buy][i+1];
                }

                dp[buy][i] = max(sum1, sum2);
            }
        }
        return dp[1][0];
    }
};