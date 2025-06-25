class Solution {
private:
    int dp[10][2][2][1024];
    int fn(int i, int tight, int repeated, int bitMask, string &str) {
        if (i == str.size()) {
            return bitMask && repeated;
        }

        if (dp[i][tight][repeated][bitMask] != -1) return dp[i][tight][repeated][bitMask];

        int limit = tight ? str[i] - '0' : 9;
        int ans = 0;

        for (int d  = 0; d <= limit; d++) {
            int newTight = tight & (d == limit);

            if (bitMask == 0  && d == 0) {
                ans += fn(i + 1, false, repeated, bitMask, str);
            } 
            else if (bitMask & (1 << d)) {
                ans += fn(i + 1, newTight, true, bitMask, str);
            } else  {
                ans += fn(i + 1, newTight, repeated, bitMask | (1 << d), str);
            }
        }
        return dp[i][tight][repeated][bitMask] = ans;
    }
public:
    int numDupDigitsAtMostN(int n) {
        string str = to_string(n);

        memset(dp, -1, sizeof(dp));
        
        return fn(0, true, false, 0, str);
    }
};