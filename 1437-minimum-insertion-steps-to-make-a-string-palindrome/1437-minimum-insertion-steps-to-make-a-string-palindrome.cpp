class Solution {
private:
    vector<vector<int>> dp;
    int fn(int i, int j, string &s) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int equal = 1e5, notEqual = 1e5;

        if (s[i] == s[j]) { 
            equal = fn(i + 1, j - 1, s);
        }
        else notEqual = 1 +  min(fn(i + 1, j, s), fn(i, j - 1, s));

        return dp[i][j] = min(equal, notEqual);
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        dp.clear();
        dp.resize(n, vector<int> (n, -1));
        return fn(0, s.size() - 1, s);
    }
};