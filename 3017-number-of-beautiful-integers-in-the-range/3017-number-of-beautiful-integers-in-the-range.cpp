class Solution {
int dp[11][2][11][11][2][21];
int fn (int i, bool tight, int oddCount, int evenCount, bool validNum, int rem, string &str, int &k) {
    if (i >= str.size()) {
        return (oddCount == evenCount && rem == 0);
    }

    if (dp[i][tight][oddCount][evenCount][validNum][rem]  != -1) return dp[i][tight][oddCount][evenCount][validNum][rem];

    int limit = tight ? str[i] - '0' : 9;

    int ans = 0;
    for (int d = 0; d <= limit; d++) {
        bool newTight = tight & (d == limit);

        if (validNum == false && d == 0) {
            ans += fn (i + 1, newTight, oddCount, evenCount, false, rem, str, k);
        } else if (d % 2 == 0) {
            ans += fn(i + 1, newTight, oddCount, evenCount + 1, true, (rem * 10 + d) % k, str, k);
        } else if (d % 2 != 0) {
            ans += fn(i + 1, newTight, oddCount + 1, evenCount, true, (rem * 10 + d) % k, str, k);
        }
    }

    return dp[i][tight][oddCount][evenCount][validNum][rem] = ans;
 }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string num1 = to_string(low - 1);
        string num2 = to_string(high);
        
        memset(dp, -1, sizeof(dp));
        int ans1 = fn(0, true, 0, 0, false, 0, num1, k);

        memset(dp, -1, sizeof(dp));
        int ans2 = fn(0, true, 0, 0, false, 0, num2, k);

        return ans2 - ans1;
    }
};