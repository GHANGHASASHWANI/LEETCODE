class Point{
    public:
    int row;
    int col;
    Point(int row, int col){
        this->row = row;
        this->col = col;
    }
};
class Solution {
private:
    bool isSafe(const int row, const int col,const vector<vector< char >>& board){
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
    }
    bool onEdge(const int row, const int col, const vector<vector< char >>& board){
        return row == 0 || col == 0 || row == board.size() - 1 || col == board[0].size() - 1;
    }
    void BFS(queue< Point >& queueBFS, vector<vector< char >>& board, vector<vector< bool>>& visited){
        const int dRow[4] = {1, -1, 0, 0};
        const int dCol[4] = {0, 0, -1, 1};

        while(not queueBFS.empty()){
            Point currPoint = queueBFS.front();
            queueBFS.pop();
            int currRow = currPoint.row;
            int currCol = currPoint.col;

            board[currRow][currCol] = '.';

            for(int i = 0; i < 4; i++){
                int newRow = currRow + dRow[i];
                int newCol = currCol + dCol[i];

                if(isSafe(newRow, newCol, board) && not visited[newRow][newCol] && board[newRow][newCol] == 'O'){
                    visited[newRow][newCol] = true;
                    queueBFS.push(Point(newRow, newCol));
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        const int rowLen = board.size();
        const int colLen = board[0].size();

        queue< Point > queueBFS;
        vector<vector< bool >> visited(rowLen, vector<bool> (colLen, false));

        for(int i =0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(board[i][j] == 'O' && onEdge(i, j, board)){
                    queueBFS.push(Point(i, j));
                    visited[i][j] = true;
                }
            }
        }

        BFS(queueBFS, board, visited);

        for(int i =0; i < rowLen; i++){
            for(int j =0; j < colLen; j++){
                if(board[i][j] ==  '.'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            
            }
        }

    }
};