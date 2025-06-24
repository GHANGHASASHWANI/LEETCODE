class Solution {
private:
    // bool isPalindrome(string &s) {
    //     int size = s.size();
    //     for (int i = 0; i < size / 2; i++) {
    //         if (s[i] != s[size - 1 - i]) return false;
    //     }
    //     return true;
    // }
public:
    string longestPalindrome(string s) {
        // string ans = "";

        // for (int  i =0; i < s.size(); i++) {
        //     string temp = "";
        //     for (int j = i; j < s.size(); j++) {
        //         temp += s[j];
        //         if (temp.size() > ans.size() && isPalindrome(temp)) {
        //             ans = temp;
        //         }
        //     }
        // }
        // return ans;

        int start = 0, end = 0;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                end = i + 1;
            }
           
        }

        for (int diff = 2; diff < n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    start = i;
                    end = j;
                }
            }
        }
        string ans  = "";

        for (int i = start; i <= end; i++) {
            ans += s[i];
        }
        return ans;
    }
};