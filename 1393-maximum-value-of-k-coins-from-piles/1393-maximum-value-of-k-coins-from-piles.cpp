class Solution {
private:
    // vector<vector<vector< int >>> dp;
    // int fn(int idx, int j, vector<vector< int >>&arr, int k){
    //     if(k <= 0 || idx >= arr.size() || j >= arr[idx].size()){
    //         return 0;
    //     }
    //     if(dp[idx][j][k] != -1) return dp[idx][j][k];
    //     int ans = 0;

    //     ans = max(ans, arr[idx][j] + fn(idx+1, 0, arr, k-1));
    //     ans = max(ans, arr[idx][j] + fn(idx, j+1, arr, k-1));
    //     ans = max(ans, fn(idx+1, 0, arr, k));
    //     // cout<<ans<<endl;
    //     return dp[idx][j][k] = ans;
    // }

    vector<vector< int >> dp;

    int fn(int i, vector<vector< int >> &arr, int k){
        if(i >= arr.size() || k <= 0) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int ans = fn(i +1, arr, k);

        int sum = 0;

        for(int j = 0; j < min(k, (int)arr[i].size()); j++){
            sum += arr[i][j];
            ans = max(ans, sum + fn(i+1, arr, k - (j+1)));
        }

        return dp[i][k] = ans;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // dp.clear();
        // int size1 = 0;
        // for(auto i : piles){
        //     size1 = max({size1, (int)i.size()});
        // }
        // dp.resize(piles.size() +1, (vector<vector< int >> (size1, vector<int> (k+1, -1))));
        // return fn(0, 0, piles, k);

        dp.clear();
        dp.resize(piles.size()+1, vector< int > (k+1, -1));

        return fn(0, piles, k);

    }
};