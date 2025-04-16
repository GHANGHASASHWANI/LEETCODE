class Solution {
private:
    void DFS(int node, vector< bool > & visited, const vector<vector< int >> &isConnected){
        visited[node] = true;

        for(int idx = 0; idx < isConnected[node].size(); idx++){
            if(isConnected[node][idx] == 1 && not visited[idx]){
                DFS(idx, visited, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalVertex = isConnected.size();

        vector< bool > visited(totalVertex, false);
        int totalProvinces = 0;

        for(int index = 0; index < totalVertex; index++){
            if(not visited[index]){
                totalProvinces++;
                DFS(index, visited, isConnected);
            }
        }

        return totalProvinces;
    }
};