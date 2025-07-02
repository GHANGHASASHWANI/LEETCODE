class Solution {
private:
    void dfs(vector<int> &result, int node, vector<vector<int>> &adjList, map<char, int> &mpp, string &labels, int parent) {
        int currCount = mpp[labels[node]];
        for (auto &neighbor : adjList[node]) {
            if (neighbor == parent) continue;
            dfs(result, neighbor, adjList, mpp, labels, node);
        }
        mpp[labels[node]]++;
        // cout<<mpp[labels[node]]<<" "<<currCount<<" "<<node<<endl;
        result[node] = (mpp[labels[node]] - currCount);
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
        map<char, int> mpp;
        dfs(allLabel, 0, adjList, mpp, labels, -1);

        return allLabel;
    }
};