class Solution {
public:
    vector<vector<int>> dp;
    int totalWays(vector<vector<int>>&obstacles, int row, int col){
        if(row >= obstacles.size() || col >= obstacles[0].size() || row < 0 || col < 0) return 0;
        if(obstacles[row][col] == 1) return 0;

        if(row == obstacles.size() -1 && col == obstacles[0].size() - 1) return 1;

        if(dp[row][col] != -1) return dp[row][col];
        
        int right = totalWays(obstacles, row + 1, col);
        int left = totalWays(obstacles, row, col + 1);

        return dp[row][col] = left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size() -1;
        int col = obstacleGrid[0].size() -1;
        dp.clear();
        dp.resize(105, vector<int> (105, -1));
        if(obstacleGrid[row][col] == 1) return 0;
        return totalWays(obstacleGrid, 0, 0);
    }
};