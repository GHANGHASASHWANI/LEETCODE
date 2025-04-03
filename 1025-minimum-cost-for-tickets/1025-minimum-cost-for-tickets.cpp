class Solution {
private:
    vector<vector< int >> dp;
    int fn(int idx, vector<int> &days, int curr, vector<int> &cost){
        if(idx == days.size()) return 0;

        if(dp[idx][curr] != -1) return dp[idx][curr];

        int pass1 =INT_MAX, pass2 =INT_MAX, pass3 = INT_MAX, pass4 = INT_MAX;

        if(curr < days[idx]){
            pass1 = cost[0] + fn(idx+1, days, days[idx], cost);
            pass2 = cost[1] + fn(idx+1, days, 6 + days[idx], cost);
            pass3 = cost[2] + fn(idx+1, days, 29 + days[idx], cost);
        }else{
            pass4 = fn(idx+1, days, curr, cost);
        }
       
        return dp[idx][curr] = min({pass1, pass2, pass3, pass4});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(), m = days[days.size()-1];
        dp.clear();
        dp.resize(1000, vector<int> (1000, -1));
        return fn(0, days, 0, costs);
    }
};