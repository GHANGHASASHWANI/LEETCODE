class Solution {
private:
    void dfs(vector<vector< int >> &grid, int vertex, int currNode, vector< int > &visited, int &cnt){
        visited[currNode] = 1;
        for(int i = 0; i < vertex; i++){
            if(!visited[i] ){
                if((grid[currNode][0] == grid[i][0]) || (grid[currNode][1] == grid[i][1])){
                    cnt++;
                    dfs(grid, vertex, i, visited, cnt);
                }
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int vertex = stones.size();
        vector< int > visited(vertex + 1, 0);
        int answer  = 0;
        for(int i =0; i < vertex ; i++){
            if(! visited[i]){
                dfs(stones, vertex, i, visited, answer);
            }
        }
        return answer;
    }
};