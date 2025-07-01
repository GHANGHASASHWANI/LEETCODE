class Solution {
private: 
    vector<vector<int>> paths;
    void findPath(vector<vector<int>> &adjList, int node, vector<int> &path, int destination) {
        path.push_back(node);

        if (node == destination) {
            paths.push_back(path);
        }

        for (auto &neighbor : adjList[node]) {
            findPath(adjList, neighbor, path, destination);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int destination = graph.size() - 1;
        vector<int> path;
        
        findPath(graph, 0, path, destination);

        return paths;
    }
};