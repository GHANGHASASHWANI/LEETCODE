class Solution {
private:
    int r[4] = {0, -1, 0, +1};
    int c[4] = {1, 0, -1, 0};
    int BFS(queue< pair< int, int >> &qu, vector<vector< bool >> &visited, vector<vector< int >> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        while(!qu.empty()){
            int size = qu.size();

            for(int i =0; i < size; i++){
                int row = qu.front().first;
                int col = qu.front().second;
                cout<<row<<" "<<col<<endl;
                qu.pop();

                for(int i =0; i < 4; i++){
                    int newRow = row + r[i];
                    int newCol = col + c[i];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && visited[newRow][newCol] == false){
                        qu.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
            ans++;
            cout<<ans<<endl;
        }
        if(ans > 0) ans--;
        return ans;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector< vector< bool >> visited(n, vector< bool > (m, false));

        queue<pair< int, int >> qu;

        for(int i =0; i < grid.size(); i++){
            for(int j =0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    qu.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int ans  = BFS(qu, visited, grid);
        cout<<ans<<endl;
        for(int i =0 ; i < grid.size(); i++){
            for(int j =0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    return -1;
                }
            }
        }
        return ans ;
    }
};