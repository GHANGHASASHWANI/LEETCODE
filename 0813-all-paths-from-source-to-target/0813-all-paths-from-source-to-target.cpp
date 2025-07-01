class Solution {
private: 
    vector<vector<int>> paths;
    void findPath(vector<vector<int>> &adjList, int node, vector<int> &path, int destination) {
        if (node == destination) {
            paths.push_back(path);
            return;
        }

        for (auto &neighbor : adjList[node]) {
            path.push_back(neighbor);
            findPath(adjList, neighbor, path, destination);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int destination = graph.size() - 1;
        vector<int> path;
        path.push_back(0);
        findPath(graph, 0, path, destination);

        return paths;
    }
};