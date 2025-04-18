class Solution {
public:
    typedef pair<int, int> pp;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector< pair<int, int>>> adjList(n+1);

        for(auto& edge : times){
            int vertex1 = edge[0], vertex2 = edge[1], time = edge[2];
            adjList[vertex1].push_back({vertex2, time});
        }

        priority_queue<pp, vector<pp>, greater<pp>> queueBfs;
        queueBfs.push({0, k});
        vector<int> distance(n + 1,  INT_MAX);
        distance[k] = 0;

        while(not queueBfs.empty()){
            auto [currDistance, currNode] = queueBfs.top();
            queueBfs.pop();

            for(auto& [newNode, newDistance] : adjList[currNode]){
                if(distance[newNode] > newDistance + currDistance){
                    distance[newNode] = newDistance + currDistance;
                    queueBfs.push({distance[newNode], newNode});
                }
            }
        }
        int minTime = 0;

        for(int i = 1; i < distance.size(); i++){
            if(distance[i] == INT_MAX) return -1;
            minTime = max(minTime, distance[i]);
        }
        return minTime;
    }
};