class Solution {
public:
    typedef tuple<int, int, int, int> tupple;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        vector<vector<int>> minDistance(n, vector<int> (m, INT_MAX));
        minDistance[0][0] = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, false));

        priority_queue<tupple, vector<tupple>, greater<tupple>> pq;
        // queue<tupple> pq;
        pq.push({0, 0, 0, 1});

        int rows[4] = {1, -1, 0, 0};
        int cols[4] = {0, 0, 1, -1};

        while(not pq.empty()){
            auto [dist, row, col,  curr] = pq.top();
            pq.pop();

            if(visited[row][col]) continue;

            visited[row][col] = true;

            for(int i = 0; i < 4; i++){
                int newRow = row + rows[i];
                int newCol = col + cols[i];

                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m ){
                    int newdist = max(moveTime[newRow][newCol], minDistance[row][col]) + curr;
                    if(newdist < minDistance[newRow][newCol]){
                        minDistance[newRow][newCol] = newdist;
                        int newcurr= 2;
                        if(curr == 2) newcurr = 1;
                        pq.push({newdist, newRow, newCol, newcurr});
                        // cout<<newRow<<" "<<newCol<<endl;
                    }
                }

            }
        }

        return minDistance[n-1][m-1];
    }
};