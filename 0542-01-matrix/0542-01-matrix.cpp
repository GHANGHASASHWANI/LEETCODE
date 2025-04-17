class Solution {
private:
    bool isSafe(const int row, const int col,const vector<vector<int>> &mat){
        return row >= 0 && row < mat.size() && col >= 0 && col < mat[0].size();
    }

    void BFS(queue< pair< pair< int, int>, int>>& qu, const vector<vector< int >>& mat, vector<vector<int>>& distance, vector<vector<bool>>& visited){
        const int dirRow[4] = {1, -1, 0, 0};
        const int dirCol[4] = {0, 0, -1, 1};

        while(not qu.empty()){
            int currRow = qu.front().first.first;
            int currCol = qu.front().first.second;
            int currCount = qu.front().second;

            qu.pop();

            if(mat[currRow][currCol] == 1){
                distance[currRow][currCol] = currCount;
            }

            for(int i = 0; i < 4; i++){
                const int newRow = currRow + dirRow[i];
                const int newCol = currCol + dirCol[i];

                if(isSafe(newRow, newCol, mat) && not visited[newRow][newCol]){
                    visited[newRow][newCol] = true;
                    qu.push({{newRow, newCol}, currCount + 1});
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowLen = mat.size();
        int colLen = mat[0].size();

        vector<vector<int>> distance(rowLen, vector<int> (colLen, 0));
        vector<vector<bool>> visited(rowLen, vector<bool> (colLen, false));
        queue< pair< pair< int, int>, int>> qu;

        for(int i =0; i <rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = true;
                    qu.push({{i, j}, 0});
                }
            }
        }

        BFS(qu, mat, distance, visited);
        return distance;
    }
};