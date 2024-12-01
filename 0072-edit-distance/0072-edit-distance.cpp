class Solution {
public:
    int dp[505][505];
    int solve(string s1, string s2, int i, int j) {
        if (i == s1.size())
            return s2.size() - j;
        if (j == s2.size())
            return s1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int res = 1000000;

        if (s1[i] == s2[j]) {
            res = min(res, solve(s1, s2, i + 1, j + 1));
        } else {
            res = min(res, 1 + solve(s1, s2, i + 1, j + 1));
            res = min(res, 1 + solve(s1, s2, i + 1, j));
            res = min(res, 1 + solve(s1, s2, i, j + 1));
        }
        return dp[i][j] = res;
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        return solve(word1, word2, 0, 0);
    }
};