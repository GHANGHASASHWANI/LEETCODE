class Solution {
private:
    bool isSafe(const int row, const int col, const vector< vector< int >> &grid){
        return row >= 0 and row < grid.size() and col >= 0 and col < grid[0].size();
    } 

    void DFS(const int row, const int col, vector< vector< bool >> &visited, const vector<vector< int >> &image, vector<vector< int >> &coloredImage, const int newColor, const int oldColor){
        visited[row][col] = true;
        coloredImage[row][col] = newColor;

        int rows[4] = {1, -1, 0, 0};
        int cols[4] = {0, 0, 1, -1};

        for(int idx = 0; idx < 4; idx++){
            int newRow = row + rows[idx];
            int newCol = col + cols[idx];

            if(isSafe(newRow, newCol, image) and not visited[newRow][newCol] and image[newRow][newCol] == oldColor){
                DFS(newRow, newCol, visited, image, coloredImage, newColor, oldColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector< int >> coloredImage(image.begin(), image.end());
        int oldColor = image[sr][sc];

        vector<vector< bool >> visited(image.size(), vector< bool > (image[0].size(), false));

        DFS(sr, sc, visited, image, coloredImage, color, oldColor);

        return coloredImage;
    }
};