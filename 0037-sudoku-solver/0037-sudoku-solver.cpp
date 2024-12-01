class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int need) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] - '0' == need) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][col] - '0'== need) {
                return false;
            }
        }
        int rowx = (row / 3) * 3;
        int colx = (col / 3) * 3;

        for (int i = rowx; i < rowx + 3; i++) {
            for (int j = colx; j < colx + 3; j++) {
                if (board[i][j]  - '0'== need)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;
        if (col == 9)
            return solve(board, row + 1, 0);

        if (board[row][col] != '.')
            return solve(board, row, col + 1);

        for (int i = 1; i <= 9; i++) {
            if (isSafe(board, row, col, i)) {
                board[row][col] = '0' + i;
                bool retval = solve(board, row, col + 1);
                if (retval)
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board, 0, 0); }
};