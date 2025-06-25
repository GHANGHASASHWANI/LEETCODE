class Solution {
private:
    int dp[10][2][2];
    int fn(int i, bool tight, bool isValid, set<string> &digit, string &str) {
        if (i == str.size()) {
            return isValid;
        }

        if (dp[i][tight][isValid] != -1) return dp[i][tight][isValid];

        int limit = tight ? str[i] - '0' : 9;
        int ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight & (d == limit);

           if (!isValid && d == 0) {
                ans += fn(i+1, newTight, false, digit, str);
           }
           else if (!isValid && d > 0 && digit.count(to_string(d))) {
                ans += fn(i+1, newTight, true, digit, str);
           } else if (isValid && digit.count(to_string(d))) {
                ans += fn(i+1, newTight, true, digit, str);
           }
        }
        return dp[i][tight][isValid] = ans;
    }

public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        set<string> digit;
        for (auto it : digits) {
            digit.insert(it);
        }

        string str = to_string(n);

        memset(dp, -1, sizeof(dp));

        return fn(0, true, false, digit, str);
    }
};