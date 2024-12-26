class Solution {
public:
    vector<vector<int>> makeGraph(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return graph;
    }

    void farthestNode(int node, int par, int dis, vector<vector<int>>& gr,
                      pair<int, int>& res) {
        if (dis > res.first) {
            res = {dis, node};
        }
        for (auto ne : gr[node]) {
            if (ne != par) {
                farthestNode(ne, node, dis + 1, gr, res);
            }
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        auto gr1 = makeGraph(edges1), gr2 = makeGraph(edges2);

        pair<int, int> res1 = {INT_MIN, -1}, res2 = {INT_MIN, -1};
        farthestNode(0, -1, 0, gr1, res1);
        farthestNode(res1.second, -1, 0, gr1, res2);
        int diameter1 = res2.first;

        res1 = {INT_MIN, -1}, res2 = {INT_MIN, -1};
        farthestNode(0, -1, 0, gr2, res1);
        farthestNode(res1.second, -1, 0, gr2, res2);
        int diameter2 = res2.first;

        return max({diameter1, diameter2,
                    ((diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1)});
    }
};