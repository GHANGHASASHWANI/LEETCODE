class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool isCorrect(vector<vector<char>>& board, string word, int row, int col,
                   int position) {
        return row >= 0 and col >= 0 and row < board.size() and
               col < board[0].size() and board[row][col] == word[position];
    }
    bool isValid(vector<vector<char>>& board, string word, int row, int col,
                 int position) {
        if (position == word.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (isCorrect(board, word, row, col, position)) {
                char ch = board[row][col];
                board[row][col] = '.';
                if (isValid(board, word, row + dx[i], col + dy[i],
                            position + 1))
                    return true;
                board[row][col] = ch;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (isValid(board, word, i, col, 0))
                    return true;
            }
        }
        return false;
    }
};