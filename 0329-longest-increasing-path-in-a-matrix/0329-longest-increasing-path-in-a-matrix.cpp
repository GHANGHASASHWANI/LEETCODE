class Solution {
private:
    int row[4] = {1, 0, -1, 0};
    int col[4] = {0, 1, 0, -1};
    int mod = 1e9 + 7;
    vector<vector< int >> dp;
    int fn(int i, int j, vector<vector< int >> &grid){
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        for(int k = 0; k < 4; k++){
            int newr = i + row[k];
            int newc = j + col[k];
            if(newr >= 0 && newr < grid.size() && newc >= 0 && newc < grid[0].size() && grid[newr][newc] > grid[i][j]){
                ans = max(ans, 1+ fn(newr, newc, grid)) % mod;
            }
        }
        return dp[i][j] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int res = 0;
        dp.clear();
        dp.resize(grid.size()+1, vector<int> (grid[0].size(), -1));
        for(int i =0; i < grid.size(); i++){
            for(int j =0; j < grid[0].size(); j++){
                res = max(res ,  fn(i, j, grid)) % mod;
            }
        }

        return res;
    }
};