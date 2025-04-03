class Solution {
private:
    // vector<vector< int >> dp;
    // int fn(int idx, vector<int> &days, int curr, vector<int> &cost){
    //     if(idx == days.size()) return 0;

    //     if(dp[idx][curr] != -1) return dp[idx][curr];

    //     int pass1 =INT_MAX, pass2 =INT_MAX, pass3 = INT_MAX, pass4 = INT_MAX;

    //     if(curr < days[idx]){
    //         pass1 = cost[0] + fn(idx+1, days, days[idx], cost);
    //         pass2 = cost[1] + fn(idx+1, days, 6 + days[idx], cost);
    //         pass3 = cost[2] + fn(idx+1, days, 29 + days[idx], cost);
    //     }else{
    //         pass4 = fn(idx+1, days, curr, cost);
    //     }
       
    //     return dp[idx][curr] = min({pass1, pass2, pass3, pass4});
    // }
public:
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     int n = days.size(), m = days[days.size()-1];
    //     dp.clear();
    //     dp.resize(1000, vector<int> (1000, -1));
    //     return fn(0, days, 0, costs);
    // }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set< int > st(days.begin(), days.end());
        int n = days.size();
        vector< int > dp(days[n-1]+1, 0);

        for(int i =1; i < dp.size(); i++){
            if(st.find(i) == st.end()){
                dp[i] = dp[i-1];
                continue;
            }
            int pass1 = costs[0] + dp[max(i-1, 0)];
            int pass7 = costs[1] + dp[max(i-7, 0)];
            int pass30 = costs[2] + dp[max(i-30, 0)];

            dp[i] = min({pass1, pass7, pass30});
        }
        return dp[dp.size()-1];
    }
};