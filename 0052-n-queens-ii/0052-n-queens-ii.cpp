class Solution {
public:
    vector<vector<char>> grid;
    int ans = 0;

    bool placeQueen(int row, int col) {
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; j--, i--) {
            if (grid[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < grid[0].size();
             i--, j++) {
            if (grid[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve(int row) {
        if (row == grid.size()) {
            ans++;
            return;
        }
        for (int i = 0; i < grid[0].size(); i++) {
            if (placeQueen(row,i)) {
                grid[row][i] = 'Q';
                solve(row + 1);
                grid[row][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        ans = 0;
        grid.clear();
        grid.resize(n, vector<char>(n, '.'));
        solve(0);
        return ans;
    }
};