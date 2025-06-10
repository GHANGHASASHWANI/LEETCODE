class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n+ 1, vector<int> (m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++ ) {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + mat[i-1][j-1] - prefix[i-1][j-1];
            }
        }

        vector<vector<int>> res(n, vector<int> (m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int currRow = max(i - k, 0);
                int currCol = max(j - k, 0);
                int newRow = min(i + k, n - 1);
                int newCol = min(j + k, m - 1);

                currRow++, currCol++, newRow++, newCol++;

                res[i][j] = prefix[newRow][newCol] - prefix[currRow - 1][newCol] - prefix[newRow][currCol - 1] + prefix[currRow - 1][currCol - 1];

            }
        } 
        return res;
    }
};