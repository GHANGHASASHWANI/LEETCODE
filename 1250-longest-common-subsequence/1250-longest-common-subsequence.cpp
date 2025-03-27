class Solution {
public:
    vector<vector< int>> dp;
    int fn(string &str1, string &str2, int i, int j){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0, notTake = 0;
        if(str1[i] == str2[j]){
            take = 1 + fn(str1, str2, i-1, j-1);
        }
        else{
            notTake = max(fn(str1, str2, i-1, j), fn(str1, str2, i, j-1));
        }

        return dp[i][j] = max(take, notTake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size()-1, j = text2.size()-1;
        dp.resize(i+5, vector<int> (j+5, -1));
        return fn(text1, text2, i, j);
    }
};