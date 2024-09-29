class Solution {
public:

    void bfs(int node, vector<vector< int >> &isConnected , vector<int> &visited){
        visited[node] = 1;

        queue< int > qu;
        qu.push(node);
        while(qu.size()){
            int temp = qu.front();
            qu.pop();
            for(int i = 0; i< isConnected[temp-1].size(); i++){
                if(i != temp-1){
                    if(visited[i+1] == 0 && isConnected[temp-1][i] == 1){
                        visited[i+1] = 1;
                        qu.push(i+1);
                    }
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector< int> visited(n+1, 0);
        int answer  = 0;
        for(int i = 1; i <= n ; i++){
            if(visited[i] != 1){
                answer++;
                bfs(i, isConnected, visited);
            }
        }
        return answer;
    }
};