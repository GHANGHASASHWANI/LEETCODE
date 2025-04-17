class Solution {
private:
    bool DFS(int node ,const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& check, vector<bool>& path){
        visited[node] =true;
        check[node] = false;
        path[node] = true;

        for(auto& neighbor : graph[node]){
            if(visited[neighbor] && path[neighbor]){
                return true;
            }
            else if(not visited[neighbor]){
                if(DFS(neighbor, graph, visited, check, path)){
                    return true;
                }
            }
        }
        check[node] = true;
        path[node] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int totalVertex  = graph.size();
        vector<bool> visited(totalVertex, false);
        vector<bool> path(totalVertex, false);
        vector<bool> check(totalVertex, false);

        for(int i =0; i < totalVertex; i++){
            if(not visited[i]){
                DFS(i, graph, visited, check, path);
            }
        }
        vector< int > safeStates;
        for(int i =0; i < totalVertex; i++){
            if(check[i]){
                safeStates.push_back(i);
            }
        }
        return safeStates;
    }
};