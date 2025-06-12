class Solution {
private:
    vector<vector<int>> dp;
    bool fn(int i, int j, string &s, string &p) {
        if (i >= s.size() && j >= p.size()) return true;
        if (j >= p.size()) return false;

        if (dp[i][j] != -1) return dp[i][j];

        int check = (i < s.size()  && (s[i] == p[j] || p[j] == '.'));

        if ((j + 1 < p.size() && p[j + 1] == '*')) {
            return dp[i][j] = fn(i, j + 2, s, p) or (check and fn(i + 1, j, s, p));
        }
        if (check) {
            return dp[i][j] = fn(i+1, j+1, s, p);
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        dp.resize(s.size() + 5, vector<int> (p.size() + 5, -1));
        return fn(0, 0, s, p);
    }
};