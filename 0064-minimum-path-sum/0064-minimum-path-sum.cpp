class Solution {
private:
    // vector<vector<int>> dp;
    // int fn(int r, int c, vector<vector<int>>& grid) {
    //     if (r >= grid.size() || c >= grid[0].size())
    //         return 1e5;
    //     if(r == grid.size() - 1 && c == grid[0].size() - 1) return grid[r][c];

    //     if(dp[r][c] != -1) return dp[r][c];

    //     int right = fn(r, c + 1, grid);
    //     int down = fn(r + 1, c, grid);
        
    //     return dp[r][c] = grid[r][c] + min(right, down);
    // }

public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp.clear();
        // dp.resize(grid.size(), vector<int> (grid[0].size(), -1)); 
        // return fn(0, 0, grid); 
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[n-1][m-1] = grid[n-1][m-1];

        for(int c = m-2; c>=0; c--){
            dp[n-1][c] = grid[n-1][c] + dp[n-1][c+1];
        }
        for(int r = n-2; r >= 0; r--){
            dp[r][m-1] = grid[r][m-1] + dp[r+1][m-1];
        }

        for(int r = n-2; r >= 0; r--){
            for(int c = m-2; c >= 0; c--){
                int right = dp[r][c+1];
                int down = dp[r+1][c];
                dp[r][c] = grid[r][c] + min(right, down);
            }
        }

        return dp[0][0];
    }
};