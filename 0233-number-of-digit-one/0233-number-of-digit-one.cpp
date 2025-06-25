class Solution {
private:
    int dp[10][2][10];
    int fn(int i, bool tight, int count, string &str) {
        if (i == str.size()) return count;

        if (dp[i][tight][count] != -1) return dp[i][tight][count];

        int limit = tight ? str[i] - '0' : 9;
        int ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight & (d == limit);
            if (d == 1) {
                ans += fn(i + 1, newTight, count + 1, str);
            } else {
                ans += fn(i + 1, newTight, count, str);
            }
        }
        return dp[i][tight][count] = ans;
    }
public:
    int countDigitOne(int n) {
        string str = to_string(n);
        memset(dp, -1, sizeof(dp));

        return fn(0, true, 0, str);
    }
};