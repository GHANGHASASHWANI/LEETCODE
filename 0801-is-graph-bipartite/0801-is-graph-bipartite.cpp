class Solution {
public:

    // bool checkGraph(vector<vector<int>>& graph, vector<int> &color, int node){
    //     queue<int> qu;
    //     qu.push(node);
    //     color[node] = 0;
    //     while(qu.size()){
    //         int temp = qu.front();
    //         qu.pop();
    //         for(auto it: graph[temp]){
    //             if(color[it] == -1){
    //                 color[it] = !color[temp];
    //                 qu.push(it);
    //             }
    //             else if (color[it] == color[temp]){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool checkGraph(vector<vector< int >> &graph, vector< int > &color, int current, int previousColor){

        for(auto node : graph[current]){
            if(color[node] == -1){
                color[node] = not color[current];
                // cout<<"color seq "<<node << " " << color[node]<< endl;
                if( not checkGraph(graph, color, node, color[node])) return false;
            }
            else if(color[node] == color[current]){
                // cout<<" stopped "<< node <<" "<< current<<" " << color[node] << endl;
                return false;
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                color[i] = 0;
                bool ans = checkGraph(graph,color,i, 0);
                if(!ans) return false;
            }
        }
    return true;
    }
};