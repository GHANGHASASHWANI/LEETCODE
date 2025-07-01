class Solution {
private:
    bool isCycle(vector<int> &visited, int node, vector<vector<int>> &adjList, int color) {
        visited[node] = color;

        for (auto &neighbor : adjList[node]) {
            if (visited[neighbor] == -1) {
                if (isCycle(visited, neighbor, adjList, !color)) return true;
            }
            else if (visited[neighbor] != -1 && (visited[neighbor] == visited[node])) {
                return true;
            }
        }
        return false;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int vertex = n + 1;
        vector<vector<int>> adjList(vertex);
        vector<int> visited(vertex, -1);

        for (auto &dislike : dislikes) {
            int firstPerson = dislike[0];
            int secondPerson = dislike[1];
            adjList[firstPerson].push_back(secondPerson);
            adjList[secondPerson].push_back(firstPerson);
        }

        for (int person = 1; person < vertex; person++) {
            if (visited[person] == -1) {
                if (isCycle(visited, person, adjList, 1)) return false;
            }
        }
        return true;
    }
};