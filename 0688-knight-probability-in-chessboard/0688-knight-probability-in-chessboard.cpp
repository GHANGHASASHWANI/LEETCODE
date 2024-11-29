class Solution {
public:
    double dp[30][30][105];

    int dx[8] = {1,2,1,2,-1,-2,-1,-2};
    int dy[8] = {2,1,-2,-1,2,1,-2,-1};

    double solve(int i, int j, int k, int n){
        if( i < 0 || j < 0 || i >=n || j >=n) return 0.0;
        if(k == 0) return 1.0;

        if(dp[i][j][k] > -0.9) return dp[i][j][k];

        double ans = 0.0;
        for(int p =0; p <8; p++){
            ans += solve(i + dx[p], j + dy[p], k-1, n)*(1.0/8.0);
        }

        return dp[i][j][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, -1, sizeof dp);
        return solve(row, column, k, n);
    }
};