class Solution {
private:
    void removeStone(vector<vector<int>> &stones, vector<bool> &visited, int vertex) {
        visited[vertex] = true;

        for (int index =  0; index < stones.size(); index++) {
            int row = stones[vertex][0];
            int col = stones[vertex][1];
            if (not visited[index] && (stones[index][0] == row || stones[index][1] == col) ) {
                removeStone(stones, visited, index);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int totalVertex = stones.size();

        vector<bool> visited(totalVertex, false);

        int total = 0;

        for (int vertex = 0; vertex < totalVertex; vertex++) {
            if (visited[vertex]) continue;

            removeStone(stones, visited, vertex);
            total++;
        }
        return totalVertex - total;
    }
};