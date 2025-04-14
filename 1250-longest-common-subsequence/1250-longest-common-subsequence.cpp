class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector< int >> dp(n+1, vector<int> (m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string res = "";
        int i =n, j = m;
        while(i && j){
            if(dp[i-1][j] == dp[i][j-1]){
                res = text1[i-1] + res;
                i--;
                j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                i = i-1;
            }else{
                j = j-1;
            }
        }
        cout<<res<<endl;
        return dp[n][m];
    }
};