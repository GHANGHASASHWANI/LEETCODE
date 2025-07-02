class DisjointSet {
    public:
    vector<int> parent;
    int count;
    DisjointSet(int size) {
        parent.resize(size, -1);
        count = size;
    }

    int findParent(int node) {
        if (parent[node] == -1) return node;

        return parent[node] = findParent(parent[node]);
    }

    void Union(int vertex1 , int vertex2) {
        int parentVertex1 = findParent(vertex1);
        int parentVertex2 = findParent(vertex2);

        if (parentVertex1 == parentVertex2) {
            return;
        }

        parent[parentVertex1] = parentVertex2;
        count--;
    }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int size = stones.size();
        DisjointSet set(size); 

        for (int vertex1 = 0; vertex1 < size; vertex1++) {
            for (int vertex2 = vertex1 + 1; vertex2 < size; vertex2++) {
                    if (stones[vertex1][0] == stones[vertex2][0] || stones[vertex1][1] == stones[vertex2][1]) {
                        set.Union(vertex1, vertex2);
                    }
            }
        }

        return size - set.count;
    }
};