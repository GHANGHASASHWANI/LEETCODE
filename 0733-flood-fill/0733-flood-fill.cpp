class Solution {
public:
void dfs(vector<vector< int >> &image, int sr, int sc, int color, int need, vector<vector<int>> &visited){
        image[sr][sc] = color;
        visited[sr][sc] = 1;
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};

        for(int i=0;i<4;i++){
            int row = sr + delrow[i];
            int col = sc + delcol[i];
            if(row>=0 && row< image.size() && col >=0 && col < image[0].size() && visited[row][col] == -1 && image[row][col] == need){
                dfs(image, row, col, color, need, visited);
            }
        }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int need = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m, vector<int> (n, -1));
        dfs(image, sr, sc, color, need, visited);
        return image;
    }
};