class TreeAncestor {
public: 
    // DP[i][j] = x = dp[i][j-1]
    //                dp[x][j-1]

    vector< vector< int >> dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp.clear();
        int k = ceil(log2(n));
        dp.resize(n, vector<int> (k+1, -1));

        for(int i =0; i < n; i++){ 
            dp[i][0] = parent[i];
        }

        for(int i = 1; i <= k; i++){ // col
            for(int j = 1; j <  n; j++ ){ // row
                int x = dp[j][i-1];
                if(x == -1) dp[j][i] = -1;
                else dp[j][i] = dp[x][i-1];
            }
        }

        for(int i = 1; i <= k; i++){ // col
            for(int j = 1; j <  n; j++ ){ // row
               cout<< dp[j][i] <<" ";
            }
            cout<<endl;
        }
    }

    int solve(int target, int k, vector< vector< int >> &dp){
        // if(k == 1) return dp[target][0];
        if(k == 0) return target;

        int j = log2(k);
        int x = dp[target][j];
        int remaining = k - pow(2, j);

        if(x == -1) return -1;

        return solve(x, remaining, dp);
    }
    
    int getKthAncestor(int node, int k) {
        return solve(node, k, dp);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */