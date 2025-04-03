class Solution {
private:
    // vector< vector< int >> dp;
    // long long fn(vector<int> & arr, int idx, int curr){
    //     if(idx >= arr.size()) return 0;
    //     if(dp[idx][curr] != -1) return dp[idx][curr];

    //     long long pick = arr[idx]*curr + fn(arr, idx+1, curr+1);
    //     long long nonPick = fn(arr, idx+1, curr);

    //     return dp[idx][curr] = max(pick, nonPick);
    // }
public:
    // int maxSatisfaction(vector<int>& satisfaction) {
    //     dp.clear();
    //     int n = satisfaction.size();
    //     dp.resize(n + 5, vector< int > (n+5, -1));
    //     sort(satisfaction.begin(), satisfaction.end());
    //     long long ans = fn(satisfaction, 0, 1);

    //     if(ans < 0) return 0;

    //     return ans;
    // }

     int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();

        vector<vector< int >> dp(n+1, vector< int > (n+1, 0));

        for(int idx = n-1; idx >= 0; idx--){
            for(int curr = idx; curr >= 0; curr--){
                long long pick = satisfaction[idx]*(curr+1) + dp[idx+1][curr+1];
                long long nonPick = dp[idx+1][curr];

                dp[idx][curr] = max(pick, nonPick);
            }
        }
        return dp[0][0];
     }
};