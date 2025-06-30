class Solution {
public:
    typedef pair<int, pair<int, int>> grid;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rowLen = maze.size(), colLen = maze[0].size();
        vector<vector<bool>> visited(rowLen, vector<bool> (colLen, false));

        priority_queue<grid, vector<grid>, greater<grid>> traverse;
        traverse.push({0, {entrance[0], entrance[1]}});

        visited[entrance[0]][entrance[1]] = true;

        int rows[4] = {1, -1, 0, 0};
        int cols[4] = {0, 0, -1, 1};

        while (not traverse.empty()) {
            int currLevel = traverse.top().first;
            int row = traverse.top().second.first;
            int col = traverse.top().second.second;
            traverse.pop();

            if ((row == 0 || col == 0 || row == rowLen - 1 || col == colLen - 1) && !(row == entrance[0] && col == entrance[1])) {
                return currLevel;
            }

            for (int i = 0; i < 4; i++) {
                int newRow = row + rows[i];
                int newCol = col + cols[i];

                if ( newRow >= 0 && newCol >= 0 && newRow < rowLen && newCol < colLen && maze[newRow][newCol] != '+' && not visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    traverse.push({currLevel + 1, {newRow, newCol}});
                }
            }
        }
        return -1;
    }
};