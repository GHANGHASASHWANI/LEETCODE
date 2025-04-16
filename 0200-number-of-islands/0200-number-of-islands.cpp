class Solution {
private:
    bool isSafe(int row, int col, const vector<vector< char >> &grid){
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }

    void DFS(int row, int col, vector<vector< bool >> &visited, const vector<vector< char >> &grid){
        visited[row][col] = true;
        int rows[4] = {1, -1, 0, 0};
        int cols[4] = {0, 0, 1, -1};

        for(int idx = 0; idx < 4; idx++){
            int newRow = row + rows[idx];
            int newCol = col + cols[idx];

            if(isSafe(newRow, newCol, grid) && not visited[newRow][newCol] && grid[newRow][newCol] == '1'){
                DFS(newRow, newCol, visited, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();

        int islands = 0;
        vector<vector< bool >> visited(rowLen, vector< bool > (colLen, false));

        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(not visited[i][j] and grid[i][j] == '1'){
                    DFS(i, j, visited, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};