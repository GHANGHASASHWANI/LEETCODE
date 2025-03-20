class Solution {
public:
    int r[4] = {0, 0, 1, -1};
    int c[4] = {1, -1, 0, 0};
    void BFS(vector<vector< int >> &answer, vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor, set< pair<int, int>> &visited){
        queue< pair< int, int >> qu;
        qu.push({sr, sc});
        while(!qu.empty()){
            int size = qu.size();

            for(int i =0; i < qu.size(); i++){
                int row = qu.front().first;
                int col = qu.front().second;
                qu.pop();
                answer[row][col] = newColor;
                for(int i =0; i < 4; i++){
                    int newRow = row + r[i];
                    int newCol = col + c[i];

                    if(newRow >= 0 && newRow < image.size() && newCol >= 0 && newCol < image[0].size() && image[newRow][newCol] == oldColor && !visited.count({newRow, newCol})){
                        qu.push({newRow, newCol});
                        visited.insert({newRow, newCol});
                    }
                }

            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector< int >> answer(image.begin(), image.end());
        set< pair<int, int>> visited;

        int oldColor = image[sr][sc];
        BFS(answer, image, sr, sc,color, oldColor, visited);

        return answer;

    }
};