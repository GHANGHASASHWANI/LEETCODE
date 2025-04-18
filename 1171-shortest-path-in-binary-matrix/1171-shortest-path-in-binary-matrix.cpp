class Point{
    private:
    int row;
    int col;
    int weight;
    public:
    int getRow(){
        return row;
    }
    int getCol(){
        return col;
    }
    int getWeight(){
        return weight;
    }
    Point(int row, int col, int weight){
        this->row = row;
        this->col = col;
        this->weight = weight;
    }
};
class Solution {
public:
    bool isSafe(const int row, const int col, vector<vector<int>>& grid){
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int rowLen = grid.size(), colLen = grid[0].size();
        if(grid[0][0] == 1 || grid[rowLen - 1][colLen - 1] == 1) return -1;

        queue<Point> queueBfs;
        queueBfs.push(Point(0, 0, 1));
        vector<vector<int>> distance(rowLen, vector<int> (colLen, INT_MAX));
        distance[0][0] = 0;

        const int dirRow[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        const int dirCol[8] = {0, 0, 1, -1, -1, -1, 1, +1};

        while(not queueBfs.empty()){
            Point& currPoint = queueBfs.front();
            int currRow = currPoint.getRow();
            int currCol = currPoint.getCol();
            int currWeight = currPoint.getWeight();
            queueBfs.pop();

            if(currRow == rowLen -1 && currCol == colLen - 1){
                return currWeight;
            }

            for(int i = 0; i < 8; i++){
                int newRow = currRow + dirRow[i];
                int newCol = currCol + dirCol[i];

                if(isSafe(newRow, newCol, grid) && grid[newRow][newCol] == 0 && (distance[newRow][newCol] > 1 + currWeight)){
                    distance[newRow][newCol] = 1 + currWeight;
                    queueBfs.push(Point(newRow, newCol, distance[newRow][newCol]));
                }
            }

        }
        return -1;
    }
};