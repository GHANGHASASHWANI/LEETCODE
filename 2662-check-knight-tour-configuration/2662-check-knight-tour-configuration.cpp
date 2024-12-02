class Solution {
public:
    int dx[8] = {2, 2, -2, -2, -1, 1, 1, -1};
    int dy[8] = {-1, 1, 1, -1, 2, 2, -2, -2};

    bool isCorrect(vector<vector<int>>& grid, int row, int col, int position) {
        return row >= 0 and col >= 0 and row < grid.size() and
               col < grid[0].size() and grid[row][col] == position;
    }
    bool isValid(vector<vector<int>>& grid, int row, int col, int position) {
        if (position == grid.size() * grid[0].size() - 1)
            return true;

        for (int i = 0; i < 8; i++) {
            if (isCorrect(grid, row + dx[i], col + dy[i], position + 1)) {
                // cout<<grid[row][col]<<" ";
                return isValid(grid, row + dx[i], col + dy[i], position + 1);
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        return isValid(grid, 0, 0, 0);
    }
};