#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    private:
    vector<int> rank, parent, size;
    public:
    disjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i =0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionByRank(int vertex1, int vertex2){
        int v1Parent = findParent(vertex1);
        int v2Parent = findParent(vertex2);

        if(v1Parent == v2Parent) return;

        if(rank[v1Parent] < rank[v2Parent]){
            parent[v1Parent] = v2Parent;
        }
        else if(rank[v2Parent] < rank[v1Parent]){
            parent[v2Parent] = v1Parent;
        }
        else{
            parent[v2Parent] = v1Parent;
            rank[v1Parent]++;
        }
    }

    void unionBySize(int vertex1, int vertex2){
        int v1Parent = findParent(vertex1);
        int v2Parent = findParent(vertex2);

        if(v1Parent == v2Parent) return;

        if(size[v1Parent] < size[v2Parent]){
            parent[v1Parent] = v2Parent;
            size[v2Parent] += size[v1Parent];
        }else{
            parent[v2Parent] = v1Parent;
            size[v1Parent] += size[v2Parent];
        }
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraEdges = 0;
        disjointSet ds(n);

        for(auto edge : connections){
            int node1 = edge[0], node2 = edge[1];
            if(ds.findParent(node1) != ds.findParent(node2)){
                ds.unionByRank(node1, node2);
            }
            else{
                extraEdges++;
            }
        }

        int need = 0;

        for(int i = 0; i < n; i++){
            if(ds.findParent(i) == i){
                need++;
            }
        }

        int finalNeed = need - 1;

        if(finalNeed > extraEdges) return -1;

        return finalNeed;
    }
};