class Solution {
private:
    int findCuts(int start, int end, const vector< int> &cuts, vector<vector< int >> & dp){
        if(start > end) return 0;

        if(dp[start][end] != -1) return dp[start][end];

        long long minCut = INT_MAX;

        for(int idx = start; idx <= end; idx++){
            long long partition1 = findCuts(start, idx - 1, cuts, dp);
            long long partition2 = findCuts(idx + 1, end, cuts, dp);
            long long length = cuts[end + 1] - cuts[start - 1];

            minCut = min(minCut, partition1 + partition2 + length);
        }
        return dp[start][end] = minCut;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        // cuts.push_back(n);
        // cuts.insert(cuts.begin(), 0);

        // sort(cuts.begin(), cuts.end());

        // int N = cuts.size();

        // vector<vector< int >> dp(N, vector< int > (N, -1));

        // return findCuts(1, N-2, cuts, dp);

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        int N = cuts.size();

        vector<vector< int >> dp(N, vector<int> (N, 0));

        for(int i = N - 2;  i >= 1; i--){
            for(int j = 1; j <= N - 2; j++){
                if(i > j) continue;
                int miniCost = INT_MAX;
                for(int k = i; k <= j; k++){
                    int partition1 = dp[i][k-1];
                    int partition2 = dp[k+1][j];
                    int cost = cuts[j + 1] - cuts[i - 1];

                    miniCost = min(miniCost, partition1 + partition2 + cost);
                }
                dp[i][j] = miniCost;
            }
        }
        return dp[1][N-2];
    }
};