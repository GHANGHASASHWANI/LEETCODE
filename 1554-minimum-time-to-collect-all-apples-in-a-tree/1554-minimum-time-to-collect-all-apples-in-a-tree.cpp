class Solution {
private:
    bool findDistance(int node, vector<vector<int>> &adjList, vector<bool> &hasApple, int &sum, vector<bool> &visited) {
        bool mainDown = false;
        visited[node] = true;
        for (auto &neighbor : adjList[node]) {
            if (not visited[neighbor]) {
                bool down = findDistance(neighbor, adjList, hasApple, sum, visited);
                if (down) {
                    sum += 2;
                    mainDown = true;
                }
            }
        }
        return hasApple[node] || mainDown;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjList(n);

        for (auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int sum = 0;
        bool apple = findDistance(0, adjList, hasApple, sum, visited);
        return sum;
    }
};