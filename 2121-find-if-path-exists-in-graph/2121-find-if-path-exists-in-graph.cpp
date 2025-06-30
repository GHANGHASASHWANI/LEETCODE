class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector< int >> adjList(n);
        vector<bool> visited(n, false);

        for (auto it : edges) {
            int u = it[0], v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        queue<int> traverse;
        traverse.push(source);
        visited[source] = true;

        while (not traverse.empty()) {
            int currNode = traverse.front();
            traverse.pop();

            if (currNode == destination) return true;

            for (auto neighbor : adjList[currNode]) {
                if (not visited[neighbor]) {
                    visited[neighbor] = true;
                    traverse.push(neighbor);
                }
            }
        }
        return false;
    }
};