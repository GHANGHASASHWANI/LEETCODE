class Solution {
private:
    vector<vector<int>> dp;
    int fn(int i, int j, string &s, string &t) {
        if (j < 0) return 1;
        if (i == 0 && j == 0) return s[i] == t[j] ? 1 : 0;
        if (i == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans1 = 0, ans2 = 0;
        if (s[i] == t[j]) {
            ans1 = fn(i - 1, j - 1, s, t);
        } 
        ans2 = fn(i - 1, j, s, t);
        
        return dp[i][j] = ans1 + ans2;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.resize(n, vector<int> (m, -1));

        return fn(n - 1, m - 1, s, t);
    }
};