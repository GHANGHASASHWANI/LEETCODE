class Solution {
public:
    int result = INT_MAX, total;
    vector<int> vals;
    vector<vector<int>> adjList;

    int dfs2(int node, int parent, int ans1, int ancestor) {
        int xorr = vals[node];
        for (auto &neighbor : adjList[node]) {
            if (neighbor == parent) continue;
            xorr = xorr ^ dfs2(neighbor, node, ans1, ancestor);
        }
        if (parent == ancestor) return xorr;
        result = min(result, max({ans1, xorr, total ^ ans1 ^ xorr}) - min({ans1, xorr, total ^ans1 ^ xorr}));
        return xorr;
    }

    int dfs(int node, int parent) {
        int xorr = vals[node];

        for (auto &neighbor : adjList[node]) {
            if (neighbor == parent) continue;
            xorr = xorr ^ dfs(neighbor, node);
        }
        
        for (auto &neighbor : adjList[node]) {
            if (neighbor == parent) 
            dfs2(neighbor, node, xorr, node);
        }
        return xorr;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int sum = 0;
        int size = nums.size();
        adjList.resize(size);

        for (auto &edge: edges) {
            int vertex1 = edge[0], vertex2 = edge[1];
            adjList[vertex1].push_back(vertex2);
            adjList[vertex2].push_back(vertex1);
        }

        for (auto &val : nums) {
            sum = sum ^ val;
        }
        vals = nums;
        total = sum;
        dfs(0, -1);
        return result;
    }
};