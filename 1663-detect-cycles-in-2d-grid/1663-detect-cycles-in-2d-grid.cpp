class Solution {
private:

    bool isSafe(const int row, const int col, const vector<vector<char>> &grid){
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }

    int DFS(const int currRow, const int currCol, const int prevRow, const int prevCol, vector<vector<bool>> &visited, const vector<vector<char>> &grid){
        visited[currRow][currCol] = true;

        const int dirRow[4] = {-1, 1, 0, 0};
        const int dirCol[4] = {0, 0, -1, 1};

        for(int idx = 0; idx < 4; idx++){
            int newRow = currRow + dirRow[idx];
            int newCol = currCol + dirCol[idx];

            if(isSafe(newRow, newCol, grid) && visited[newRow][newCol]  && !(newRow == prevRow && newCol == prevCol) && grid[newRow][newCol] == grid[currRow][currCol]){
                return true;
            }
            else if(isSafe(newRow, newCol, grid) && not visited[newRow][newCol] && grid[newRow][newCol] == grid[currRow][currCol]){
                if(DFS(newRow, newCol, currRow, currCol, visited, grid)){
                    return true;
                }
            }

        }

        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();

        vector<vector<bool>> visited(rowLen, vector<bool> (colLen, false));

        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(!visited[i][j]){
                    bool checkCycle = DFS(i, j, i, j, visited, grid);
                    if(checkCycle){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};