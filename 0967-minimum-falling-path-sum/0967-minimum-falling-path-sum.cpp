class Solution {
public:
    // vector<vector< int >> dp;
    // int fn(int row, int col, vector<vector<int>> &matrix){
    //     if(row == matrix.size()-1){
    //         return matrix[row][col];
    //     }
    //     if(dp[row][col] != -1) return dp[row][col];
    //     int sum1, sum2, sum3;
    //     sum1 = sum2 = sum3 = INT_MAX;
    //     if(col >= 0) sum1 = fn(row+1, col, matrix);
    //     if(col - 1 >= 0) sum2 = fn(row+1, col -1, matrix);
    //     if(col + 1 < matrix[0].size()) sum3 = fn(row+1, col +1, matrix);

    //     return dp[row][col] = matrix[row][col] + min({sum1, sum2, sum3});
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     dp.clear();
    //     dp.resize(matrix.size() + 1, vector<int> (matrix[0].size()+1, -1));
    //     int ans = INT_MAX;

    //     for(int i =0; i < matrix[0].size(); i++){
    //         int temp = fn(0, i, matrix);
    //         // cout<<temp<<endl;
    //         ans = min(ans, temp);
            
    //     }
    //     return ans;
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 10e5));

        for(int i = 0; i < m; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i =1; i < n; i++){
            for(int j = 0; j < m; j++){
                int sum1, sum2, sum3;
                sum1 = sum2 = sum3 = 10e5;
                if(j >= 0 ) sum1 = dp[i-1][j];
                if(j - 1 >= 0 ) sum2 = dp[i-1][j-1];
                if(j + 1 < m ) sum3 = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + min({sum1, sum2, sum3});
            }
        }

        int ans = INT_MAX;
        for(int i =0; i < m; i++){
            ans = min(ans, dp[n-1][i]);
        }

        return ans;

    }

};