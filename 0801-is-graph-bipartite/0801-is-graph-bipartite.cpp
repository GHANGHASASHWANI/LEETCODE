class Solution {
private:
    bool checkGraph(const int node, const vector<vector< int >>& graph, vector< int > &color){
        queue< int > queueBfs;
        queueBfs.push(node);
        color[node] = 0;

        while(not queueBfs.empty()){
            int currNode = queueBfs.front();
            queueBfs.pop();

            for(auto& newNode : graph[currNode]){
                if(color[newNode] == -1){
                    color[newNode] = not color[currNode];
                    queueBfs.push(newNode);
                }
                else if(color[newNode] == color[currNode]){
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int totalVertex = graph.size();

        vector< int > color(totalVertex, -1);

        for(int i =0; i < totalVertex; i++){
            if(color[i] == -1 && not checkGraph(i, graph, color)){
                return false;
            }
        }
        return true;
    }
};