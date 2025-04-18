class Point{
    private:
    int row;
    int col;
    int weight;
    public:
    int getRow() const{
        return row;
    }
    int getCol() const{
        return col;
    }
    const int getWeight() const{
        return weight;
    }
    Point(int row, int col, int weight){
        this->row = row;
        this->col = col;
        this->weight = weight;
    }
    bool operator>(const Point& other) const {
        return this->weight > other.weight;
    }
};
class Solution {
public:
    bool isSafe(const int row, const int col, const vector<vector<int>>& grid){
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rowLen = heights.size(), colLen = heights[0].size();

        priority_queue< Point, vector<Point>, greater<Point>> minPath;
        minPath.push(Point(0, 0, 0));
        vector<vector<int>> distance(rowLen, vector<int> (colLen, INT_MAX));
        distance[0][0] = 0;

        const int dRow[4] = {1, -1, 0, 0};
        const int dCol[4] = {0, 0, 1, -1};

        while(not minPath.empty()){
            const Point& currPoint = minPath.top();
            int currRow = currPoint.getRow();
            int currCol = currPoint.getCol();
            int currWeight = currPoint.getWeight();
            minPath.pop();

            if(currRow == rowLen - 1 && currCol == colLen - 1){
                return currWeight;
            }

            for(int i =0; i < 4; i++){
                int newRow = currRow + dRow[i];
                int newCol = currCol + dCol[i];

                if(isSafe(newRow, newCol, heights)){
                    int newDiff = abs(heights[currRow][currCol] - heights[newRow][newCol]);
                    int newEffort = max(currWeight, newDiff);

                    if(newEffort < distance[newRow][newCol]){
                        distance[newRow][newCol] = newEffort;
                        minPath.push(Point(newRow, newCol, distance[newRow][newCol]));
                    }
                }
            }
        }
        return 0;
    }
};