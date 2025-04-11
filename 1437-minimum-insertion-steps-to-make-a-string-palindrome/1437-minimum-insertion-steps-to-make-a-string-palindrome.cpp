class Solution {
private:
    vector<vector<int>> dp;
    int fn(int i, int j, string &str){
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans1 = 0, ans2 = 0;

        if(str[i] == str[j]){
            ans1 = fn(i+1, j-1, str);
        }else{
            ans1 = 1 + min(fn(i+1, j, str), fn(i, j-1, str));
        }
        return dp[i][j] = ans1;
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        // dp.clear();
        // dp.resize(n, vector<int> (n, -1));
        // return fn(0, n-1, s);

        dp.clear();
        dp.resize(n+1, vector<int> (n+1, 0));

        for(int i =n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                int ans1 = 0;
                if(s[i] == s[j]){
                    ans1 = dp[i+1][j-1];
                }else{
                    ans1 = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
                dp[i][j] = ans1;
            }
        }
        return dp[0][n-1];
    }
};