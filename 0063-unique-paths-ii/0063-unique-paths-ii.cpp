class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        if ((obstacleGrid[rows - 1][cols - 1] == 1) ||
            (obstacleGrid[0][0] == 1))
            return 0;
        vector<vector<int>> ways(rows, vector<int>(cols, 0));

        // Base case for 0th row
        for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
            if (obstacleGrid[rowIndex][0] != 1) {
                ways[rowIndex][0] = 1;
            } else {
                break;
            }
        }
        // Base case for 0th column
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            if (obstacleGrid[0][colIndex] != 1) {
                ways[0][colIndex] = 1;
            } else {
                break;
            }
        }

        for (int rowIndex = 1; rowIndex < rows; rowIndex++) {
            for (int colIndex = 1; colIndex < cols; colIndex++) {
                if (obstacleGrid[rowIndex][colIndex] == 1) {
                    ways[rowIndex][colIndex] = 0; // To prevent use of the path
                } else {
                    ways[rowIndex][colIndex] = ways[rowIndex - 1][colIndex] +
                                               ways[rowIndex][colIndex - 1];
                }
            }
        }

        return ways[rows - 1][cols - 1];
    }
};