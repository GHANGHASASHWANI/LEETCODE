class Solution {
private:
    vector<vector<int>> dp;
    int fn(int r, int c, vector<vector<int>>& grid) {
        if (r >= grid.size() || c >= grid[0].size())
            return 1e5;
        if(r == grid.size() - 1 && c == grid[0].size() - 1) return grid[r][c];

        if(dp[r][c] != -1) return dp[r][c];

        int right = fn(r, c + 1, grid);
        int down = fn(r + 1, c, grid);
        
        return dp[r][c] = grid[r][c] + min(right, down);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        dp.clear();
        dp.resize(grid.size(), vector<int> (grid[0].size(), -1)); 
        return fn(0, 0, grid); 
    }
};