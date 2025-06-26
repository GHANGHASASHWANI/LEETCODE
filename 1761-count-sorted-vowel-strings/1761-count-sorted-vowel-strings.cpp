class Solution {
private:
    

    int dp[5][51];

    int fn(int i,  int count, string &str, int n) {
        if (i >= str.size()) {
            return 0;
        }
        if (count == n) return 1;

        if (dp[i][count] != -1) return dp[i][count];
        
        int pick = 0, nonPick = 0;

        pick =  fn(i, count + 1, str, n);

        nonPick = fn(i + 1, count, str, n);

        return  dp[i][count] = pick + nonPick;
    }
public:
    int countVowelStrings(int n) {
        string str = "aeiou";

        memset(dp, -1, sizeof(dp));

        return fn(0, 0, str, n);
    }
};