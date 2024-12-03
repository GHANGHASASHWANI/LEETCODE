class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int size = numCourses;
        vector<int> indegree(size, 0);
        vector<int> res;
        vector<list<int>> graph(size);
        for (auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        queue<int> qu;

        for (int i = 0; i < size; i++) {
            if (not indegree[i]) {
                qu.push(i);
            }
        }
        while (not qu.empty()) {
            int node = qu.front();
            res.push_back(node);
            qu.pop();

            for (auto i : graph[node]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    qu.push(i);
                }
            }
        }
        return res.size() == numCourses;
    }
};