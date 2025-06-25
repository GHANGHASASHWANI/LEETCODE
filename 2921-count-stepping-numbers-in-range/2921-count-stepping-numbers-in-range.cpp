class Solution {
private:
    long long dp[101][2][2][10];
    int mod = 1e9 + 7;
    long long fn(int i, bool tight, bool isValid, int prev, string &str) {
        if (i == str.size()) {
            return  isValid;
        }

        if (dp[i][tight][isValid][prev] != -1)  return dp[i][tight][isValid][prev] ;


        int limit = tight ? str[i] - '0' : 9;
        long long ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight & (d == limit);

            if (!isValid && d == 0) {
                ans = (ans +  fn(i+1, newTight, false, prev, str) % mod) % mod;
            } 
            else if (!isValid && d > 0) {
                ans = (ans + fn(i+1, newTight, true, d, str) % mod ) % mod;
            }
            else if (abs((d - prev)) == 1) {
                ans = (ans +  fn(i+1, newTight, true, d, str) % mod ) % mod;
            }
        }
        return dp[i][tight][isValid][prev]  = ans % mod;
    }
public:
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        long long count1 = fn(0, true, false, 0, low);

        memset(dp, -1, sizeof(dp));
        long long count2 = fn(0, true, false, 0, high);

        // cout<<count1<<" "<<count2<<endl;

        bool check = false;

        for (int i = 1; i < low.size(); i++) {
            if (abs(low[i] - low[i - 1]) != 1) {
                check = true;
                break;
            }
        }
        if (!check) {
            count1--;
        }

        return ((count2 - count1) % mod + mod ) % mod;
    }
};