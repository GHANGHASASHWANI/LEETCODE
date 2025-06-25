class Solution {
private:
    int dp[32][2][2];
    int fn (int i, int tight, int prev, string &str) {
        if (i == str.size()) return 1;

        if (dp[i][tight][prev] != -1) return dp[i][tight][prev];

        int limit = tight ? str[i] - '0' : 1;
        int ans  = 0;
        for (int d =0; d <= limit; d++) {
            int newTight = tight & (d == limit);

            if (prev && d == 1) {
                return ans;
            } else {
                ans  += fn(i + 1, newTight, d == 1, str);
            }
        }
        return dp[i][tight][prev] = ans;
    } 
public:
    int findIntegers(int n) {
        string str = "";
        while (n > 0) {
            int rem = n % 2;
            n /= 2;
            str += (rem + '0');
        }
        reverse(str.begin(), str.end());

        memset(dp, -1, sizeof(dp));
        
        return fn(0, true, 0, str);
    }
};