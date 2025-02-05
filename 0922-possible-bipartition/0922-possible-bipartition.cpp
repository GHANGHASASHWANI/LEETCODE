class Solution {
public:

    int isCycle(int node, int parent,int color, vector< int > &visited, vector<vector<int>> &adjlist){
        visited[node] = color;

        for(auto neighbour : adjlist[node]){
            if(visited[neighbour] == -1){
                if(!isCycle(neighbour, node, 1 - color, visited, adjlist)) return false;
            }
            else if(visited[neighbour] == visited[node]){
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector< int >> adjlist(n+1);
        vector< int > visited(n+1, -1);
        for(auto it : dislikes){
            adjlist[it[0]].push_back(it[1]);
            adjlist[it[1]].push_back(it[0]);
        }
        
        for(int i = 1; i <= n; i++){
            if(visited[i] == -1){
                if(!isCycle(i, -1,0, visited, adjlist)) return false;
            }
           
        }
        return true; 
    }
};