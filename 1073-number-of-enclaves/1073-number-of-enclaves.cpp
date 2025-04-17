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
    // Check whether the row and column are valid
    bool isSafe(const int row, const int col, const vector<vector< int >>& grid){
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }
    void Bfs(queue< Point>& queueBfs, const vector<vector< int >>& grid, vector<vector<bool>>& visited){
        const int dRow[4] = {1, -1, 0, 0};
        const int dCol[4] = {0, 0, -1, 1};

        // Traverse over all the 1's on the edge
        while(not queueBfs.empty()){
            const Point& currPoint =  queueBfs.front();
            const int currRow = currPoint.row;
            const int currCol = currPoint.col;
            queueBfs.pop();

            // Traverse over all 4 directions
            for(int i = 0; i < 4; i++){
                int newRow = currRow + dRow[i];
                int newCol = currCol + dCol[i];

                if(isSafe(newRow, newCol, grid) && not visited[newRow][newCol] && grid[newRow][newCol] == 1){
                    visited[newRow][newCol] = true;
                    queueBfs.emplace(newRow, newCol);
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();

        queue< Point > queueBfs;
        vector<vector< bool >> visited(rowLen, vector< bool >(colLen, false));

        // Iterate on the 0th and last column 
        for(int i = 0; i < rowLen; i++){
            if(not visited[i][0] && grid[i][0] == 1){
                visited[i][0] = true;
                queueBfs.emplace(i, 0);
            }
            if(not visited[i][colLen - 1] && grid[i][colLen - 1] == 1){
                visited[i][colLen - 1] = true;
                queueBfs.emplace(i, colLen - 1);
            }
        }

        // Iterate over the 0th and last row
        for(int i =0; i < colLen; i++){
            if(not visited[0][i] && grid[0][i] == 1){
                visited[0][i] = true;
                queueBfs.emplace(0, i);
            }
            if(not visited[rowLen - 1][i] && grid[rowLen - 1][i] == 1){
                visited[rowLen - 1][i] = true;
                queueBfs.emplace(rowLen - 1, i);
            }
        }

        // traverse over all 1's connected to edge
        Bfs(queueBfs, grid, visited);

        int cntCells = 0;

        for(int i =0; i < rowLen; i++){
            for(int j =0; j < colLen; j++){
                if(not visited[i][j] && grid[i][j] == 1){
                    cntCells++;
                }
            }
        }
        return cntCells;
    }
};