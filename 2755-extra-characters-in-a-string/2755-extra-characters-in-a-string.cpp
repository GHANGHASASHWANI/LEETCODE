class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1; 
            for (int j = i; j >= 1; --j) {
                if (dict.count(s.substr(j - 1, i - j + 1))) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
            }
        }
        return dp[n];
    }
};