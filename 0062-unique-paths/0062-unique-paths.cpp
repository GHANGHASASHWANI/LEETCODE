class Solution {
public:

                        // Memoization 

    // int totalPaths(int startRow, int startCol, int endRow, int endCol, vector<vector< int >> &dp){
    //     if(startRow == endRow && startCol == endCol) return 1;
    //     if(startRow > endRow || startCol > endCol) return 0;

    //     if(dp[startRow][startCol] != -1) return dp[startRow][startCol];

    //     int rightWays = totalPaths(startRow, startCol + 1, endRow, endCol, dp);
    //     int downWays = totalPaths(startRow + 1, startCol, endRow, endCol, dp);

    //     return dp[startRow][startCol] = rightWays + downWays;
    // }
    int uniquePaths(int m, int n) {
        // int startRow = 1, startCol = 1;
        // vector<vector< int >> dp(m+1, vector<int> (n+1, -1));
        // return totalPaths(startRow, startCol, m, n, dp);

         // Tabulation 
        vector<vector< int >> dp(m, vector<int> (n, 0));

        for(int index = 0; index < m; index++){
            dp[index][0] = 1;
        }
        for(int index = 0; index < n; index++){
            dp[0][index] = 1;
        }
        for(int rowIndex = 1; rowIndex < m; rowIndex++){
            for(int colIndex = 1; colIndex < n; colIndex++){
                dp[rowIndex][colIndex] = dp[rowIndex - 1][colIndex] + dp[rowIndex][colIndex - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};