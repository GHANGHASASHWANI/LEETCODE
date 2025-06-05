class DSU {
    vector<int> parent;
    public:
    DSU (int n) {
       
        parent.resize(n+1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        // cout<<node<<" ";
        if (node == parent[node]) return node;
        
        return parent[node] = findPar(parent[node]);
    }

    void addtoDSU(int u, int v) {
        int parentU = findPar(u);
        int parentV = findPar(v);

        if (parentU == parentV) return;

        if (parentU < parentV) {
            parent[parentV] = parentU;
        } else {
            parent[parentU] = parentV;
        }
    }

};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU obj(26);

        for (int i = 0; i < s1.size(); i++) {
            int temp1 = s1[i] - 'a';
            int temp2 = s2[i] - 'a';
            obj.addtoDSU(temp1, temp2);
            obj.addtoDSU(temp2, temp1);
        }
        cout<<"ok"<<endl;

        string ans = "";

        for (int i = 0; i < baseStr.size(); i++) {
            int currParent = obj.findPar(baseStr[i] - 'a');

            ans += (currParent + 'a');
        }
        return ans;
    }
};