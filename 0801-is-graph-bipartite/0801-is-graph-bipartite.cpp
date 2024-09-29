class Solution {
public:

    bool checkGraph(vector<vector<int>>& graph, vector<int> &color, int node){
        queue<int> qu;
        qu.push(node);
        color[node] = 0;
        while(qu.size()){
            int temp = qu.front();
            qu.pop();
            for(auto it: graph[temp]){
                if(color[it] == -1){
                    color[it] = !color[temp];
                    qu.push(it);
                }
                else if (color[it] == color[temp]){
                    return false;
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                bool ans = checkGraph(graph,color,i);
                if(!ans) return false;
            }
        }
    return true;
    }
};