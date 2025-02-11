class Solution {
public:
    vector<vector< int >> dp;
    int solve(vector< int > &jd, int n, int idx, int d){
        if(d == 1){
            return *max_element(jd.begin() + idx, jd.end());
        }

        if(dp[idx][d] != -1) return dp[idx][d];

        int finalans = INT_MAX;
        int maxi = jd[idx];
        for(int i = idx; i <= n - d; i++){
            maxi = max(maxi, jd[i]);
            int res = maxi + solve(jd, n, i+1, d-1);
            finalans = min(finalans, res);
        }
        return dp[idx][d] = finalans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        dp.resize(305, vector<int> (11, -1));
        if(jd.size() < d) return -1;
        return solve(jd, jd.size(), 0, d);
    }
};