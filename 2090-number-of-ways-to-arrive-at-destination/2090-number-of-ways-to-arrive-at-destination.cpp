class Solution {
public:
    typedef pair<long long, long long> pp;
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adjList[n];

        for(auto edge : roads){
            int vertex1 = edge[0], vertex2 = edge[1], distance = edge[2];
            adjList[vertex1].push_back({vertex2, distance});
            adjList[vertex2].push_back({vertex1, distance});
        }

        vector<long long int> distance(n, 1e18);
        distance[0] = 0;

        priority_queue<pp, vector<pp>, greater<pp>> allWays;
        allWays.push({0, 0});

        vector<long long> ways(n, 0);
        ways[0] = 1;

        while(not allWays.empty()){
            auto [currDistance, currNode] = allWays.top();
            allWays.pop();

            for(auto& neighbor : adjList[currNode]){
                long long neighborNode = neighbor.first;
                long long neighborDistance = neighbor.second;
                long long newDistance = (neighborDistance + currDistance);
                if(distance[neighborNode] > newDistance){
                    ways[neighborNode] = ways[currNode];
                    distance[neighborNode] = newDistance;
                    allWays.push({ distance[neighborNode], neighborNode});
                }
                else if(distance[neighborNode] == newDistance){
                    ways[neighborNode] = (ways[neighborNode] + ways[currNode] ) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};