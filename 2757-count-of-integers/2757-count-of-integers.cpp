class Solution {
private:
    int dp[23][2][401];
    int mod = 1e9 + 7;
    long long fn(int i, bool tight, int sum, int &maxi, int &mini, string &str) {
        if (i == str.size()) {
            return sum >= mini && sum <= maxi;
        }

        if (dp[i][tight][sum] != -1) return dp[i][tight][sum];

        int limit = tight ? str[i] - '0' : 9;
        long long ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight & (d == limit);
            ans = ans + (fn(i + 1, newTight, sum + d, maxi, mini, str) % mod);
        }
        return dp[i][tight][sum] = ans % mod;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));

        long long count1 = fn(0, 1, 0, max_sum, min_sum, num1);

        memset(dp, -1, sizeof(dp));
        long long count2 = fn(0, 1, 0, max_sum, min_sum, num2);

        int sum = 0;
        for (auto it : num1) {
            sum += (it - '0');
        }
        if (sum >= min_sum && sum <= max_sum) count1--;

        return ((count2 - count1) % mod + mod ) % mod;
    }
};