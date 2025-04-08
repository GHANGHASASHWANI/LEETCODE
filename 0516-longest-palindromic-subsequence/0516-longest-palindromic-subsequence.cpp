class Solution {
private:
    vector<vector< int >> dp;
    int fn(int i, string &s1, int j, string &s2){
        if(i >= s1.size() || j >= s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans;
        if(s1[i] == s2[j]){
            ans = 1 + fn(i+1, s1, j+1, s2);
        }else{
            ans = max(fn(i+1, s1, j, s2), fn(i, s1, j+1, s2));
        }
        return dp[i][j] = ans;
    }
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        dp.clear();
        dp.resize(s.size()+1, vector<int> (s1.size(), -1));
        return fn(0, s, 0, s1);
    }
};