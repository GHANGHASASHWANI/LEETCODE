class Solution {
private:
    map<char, int> dfs(vector<int> &result, int node, vector<vector<int>> &adjList, string &labels, int parent) {
        map<char, int> mpp;

        for (auto &neighbor : adjList[node]) {
            if (neighbor == parent) continue;
            map<char, int> curr = dfs(result, neighbor, adjList, labels, node);
            
            for (auto &it : curr) {
                mpp[it.first] += it.second;
            }
        }
        mpp[labels[node]]++;
        result[node] += mpp[labels[node]];

        return mpp;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> allLabel(n, 0);
        vector<vector<int>> adjList(n);

        for (auto &edge : edges) {
            int vertex1 = edge[0];
            int vertex2 = edge[1];
            adjList[vertex1].push_back(vertex2);
            adjList[vertex2].push_back(vertex1);
        }
        map<char, int> mpp = dfs(allLabel, 0, adjList, labels, -1);

        return allLabel;
    }
};