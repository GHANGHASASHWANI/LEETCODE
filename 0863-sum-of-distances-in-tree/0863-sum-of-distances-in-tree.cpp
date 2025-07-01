class Solution {
private:
    // int findSum(vector<vector<int>> &adjList, int currNode, int n) {
    //     queue<pair<int, int>> traverse;
    //     vector<bool> visited(n, false);
        
    //     traverse.push({0, currNode});
    //     visited[currNode] = true;

    //     int currSum = 0;

    //     while (not traverse.empty()) {
    //         auto [level, node] = traverse.front();
    //         traverse.pop();

    //         currSum += level;

    //         for (auto &neighbor : adjList[node]) {
    //             if (not visited[neighbor]) {
    //                 visited[neighbor] = true;
    //                 traverse.push({level + 1, neighbor});
    //             }
    //         }
    //     }
    //     return currSum;
    // }

    void dfs(int node, vector<int> &result, vector<int> &counter, int parent, vector<vector<int>> &adjList) {

        for (auto &neighbor : adjList[node]) {
            if (neighbor == parent) continue;
            dfs(neighbor, result, counter, node, adjList);
            counter[node] += counter[neighbor];
            result[node] += result[neighbor] + counter[neighbor]; 
        }
        counter[node] += 1;
    }

    void dfs2(int node, vector<int> &result, vector<int> &counter, int parent, vector<vector<int>> &adjList) {

        for (auto &neighbor : adjList[node]) {
            if (neighbor == parent) continue;
            result[neighbor] = result[node] - counter[neighbor] + (adjList.size() - counter[neighbor]);
            dfs2(neighbor, result, counter, node, adjList);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for (auto &edge : edges) {
            int vertex1 = edge[0];
            int vertex2 = edge[1];

            adjList[vertex1].push_back(vertex2);
            adjList[vertex2].push_back(vertex1);
        }

        vector<int> result(n, 0);
        vector<int> counter(n, 0);
        dfs(0, result, counter, -1, adjList);
        dfs2(0, result, counter, -1, adjList);

        return result;
    }
};