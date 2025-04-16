class Solution {
private:

    bool isSafe(const int row,  const int col, const vector<vector< int >> &grid){
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }

    int BFS(queue< pair< pair< int, int >, int >> qu, const vector<vector< int >> &grid, vector<vector< bool >> &visited){
        const int addRows[4] = {1, -1, 0, 0};
        const int addCols[4] = {0, 0, -1, 1};

        int totalSteps = 0;

        while(not qu.empty()){
            int currRow = qu.front().first.first;
            int currCol = qu.front().first.second;
            int currCount = qu.front().second;

            qu.pop();

            totalSteps = max(currCount, totalSteps);

            for(int idx = 0; idx < 4; idx++){
                int updatedRow = currRow + addRows[idx];
                int updatedCol = currCol + addCols[idx];

                if(isSafe(updatedRow, updatedCol, grid) && not visited[updatedRow][updatedCol] && grid[updatedRow][updatedCol] == 1){
                    visited[updatedRow][updatedCol] = true;
                    qu.push({{updatedRow, updatedCol}, currCount + 1});
                }
            }
        }
        
        return totalSteps;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();

        queue< pair< pair< int, int >, int >> qu;
        vector<vector< bool >> visited(rowLen, vector< bool >(colLen, false));

        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(grid[i][j] == 2){
                   qu.push({{i, j}, 0});
                }
            }
        }

        int minSteps = BFS(qu, grid, visited);

        for(int i =0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(grid[i][j] == 1 && not visited[i][j]) return -1;
            }
        }

        return minSteps;
    }
};