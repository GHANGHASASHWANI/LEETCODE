class Coordinate{
    public:
    int dist;
    int row; 
    int col; 
    Coordinate(int dist, int row, int col){
        this->row = row;
        this->col = col;
        this->dist = dist;
    }
    bool operator> (const Coordinate &other) const {
        return this->dist > other.dist;
    }
};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        priority_queue<Coordinate, vector<Coordinate>, greater<Coordinate>> distq;
        vector<vector<int>> minDistance(n, vector<int> (m, INT_MAX));
        minDistance[0][0] = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, false));

        distq.push(Coordinate(0, 0, 0));

        const int row[4] = {0, 0, 1, -1};
        const int col[4] = {1, -1, 0, 0};

        while(not distq.empty()){
            Coordinate point = distq.top();
            distq.pop();

            int currDistance = point.dist, currRow = point.row, currCol = point.col;

            if(visited[currRow][currCol]) continue;
            visited[currRow][currCol] = true;

            for(int i =0; i < 4; i++){
                int newRow = currRow + row[i];
                int newCol = currCol + col[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && not visited[newRow][newCol]){
                    int newDist  = max(minDistance[currRow][currCol], moveTime[newRow][newCol]) + 1;
                    if(newDist < minDistance[newRow][newCol]){
                        minDistance[newRow][newCol] = newDist;
                        distq.push(Coordinate(newDist, newRow, newCol));
                    }
                }
            }
        }
        return minDistance[n - 1][m - 1];
    }
};