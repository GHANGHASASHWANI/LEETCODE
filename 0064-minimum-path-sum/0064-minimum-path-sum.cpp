class Solution {
public:
vector<vector<int>> dp;
    int shortestPath(int row, int col, vector<vector<int>> &grid){
        if(row == grid.size() -1 && col == grid[0].size() -1) return grid[row][col];
        if(row >=grid.size() || col >= grid[0].size()) return 10000005;

        if(dp[row][col] != -1) return dp[row][col];

        int left = grid[row][col] + shortestPath(row + 1, col, grid);
        int right = grid[row][col] + shortestPath(row, col +1, grid);

        return dp[row][col] = min(left, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.clear();
        dp.resize(205, vector<int> (205, -1));
        return shortestPath(0, 0, grid);
    }
};