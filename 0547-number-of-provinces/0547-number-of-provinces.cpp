class Solution {
public:
    void DFS(int v, vector<vector< int >> &adj, vector< bool > & vis){
        vis[v] = true;

        for(auto & i : adj[v]){
            if(! vis[i]){
                DFS(i, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertex = isConnected.size();
        vector<vector<int>> adj(vertex);
        vector<bool> vis(vertex, false);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (i != j && isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans  = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(! vis[i]){
                DFS(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
};