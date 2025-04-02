class Solution {
public:
    vector<vector<int>> dp;
    // int fn(string &str1, string &str2, int i, int j){
    //     if(i < 0 || j < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int take = 0, notTake = 0;
    //     if(str1[i] == str2[j]){
    //         take = 1 + fn(str1, str2, i-1, j-1);
    //     }
    //     else{
    //         notTake = max(fn(str1, str2, i-1, j), fn(str1, str2, i, j-1));
    //     }

    //     return dp[i][j] = max(take, notTake);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        // int i = text1.size()-1, j = text2.size()-1;
        // dp.resize(i+5, vector<int> (j+5, -1));
        // return fn(text1, text2, i, j);

        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = (int)(text1[0] == text2[0]);
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0],(int)(text1[i] == text2[0]));
        }
        for (int i = 1; i < m; i++) {
            dp[0][i] = max(dp[0][i-1],(int)(text1[0] == text2[i]));
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <m; j++){
            int take = 0, notTake = 0;
            if (text1[i] == text2[j]) {
                take = 1 + dp[i - 1][j - 1];
            } else {
                notTake = max(dp[i - 1][j], dp[i][j - 1]);
            }

            dp[i][j] = max(take, notTake);
            }
        }
            
        // for(int i =0; i < n; i++){
        //     for(int j =0; j <m; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n - 1][m - 1];
    }
};