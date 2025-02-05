class Solution {
public:
    bool dfs(int node, int c, vector<int> &color, vector<vector<int>> &adjlist) {
        color[node] = c;
        
        for (auto neighbour : adjlist[node]) {
            if (color[neighbour] == -1) { 
                if (!dfs(neighbour, 1 - c, color, adjlist)) return false;
            } 
            else if (color[neighbour] == color[node]) { 
                return false;
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjlist(n + 1);
        vector<int> color(n + 1, -1); 

        for (auto it : dislikes) {
            adjlist[it[0]].push_back(it[1]);
            adjlist[it[1]].push_back(it[0]);
        }
        
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, adjlist)) return false;
            }
        }
        
        return true;
    }
};
