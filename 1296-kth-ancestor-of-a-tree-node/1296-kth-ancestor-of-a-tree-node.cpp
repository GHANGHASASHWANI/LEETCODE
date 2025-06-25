class TreeAncestor {
private:
vector<vector<int>> binary;
public:
    TreeAncestor(int n, vector<int>& parent) {
        binary.resize(31, vector<int> (n, -1));

        for (int i = 0; i < parent.size(); i++) {
            binary[0][i] = parent[i];
        }

        for (int i = 1; i < 31; i++) {
            for (int j = 0; j < n; j++) {
                int prev = binary[i - 1][j];
                if (prev != -1) {  
                    binary[i][j] = binary[i - 1][prev];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int need = k;

        for (int i = 0; i < 31 ; i++) {
            if ((k >> i) & 1) {
                node = binary[i][node];
                if (node == -1) break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */