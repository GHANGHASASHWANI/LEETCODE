class Solution {
private:
    bool checkPalindrome(int i, int j, const string &str){
        while(i < j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int miniCut(int idx, const string &str, vector< int > &dp){
        if(idx == str.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int miniCost = INT_MAX;
        for(int i = idx; i < str.size(); i++){
            if(checkPalindrome(idx, i, str)){
                int cost = 1 + miniCut(i + 1, str, dp);
                miniCost = min(cost, miniCost);
            }
        }
        return dp[idx] = miniCost;
    }
public:
    int minCut(string s) {
        // vector< int > dp(s.size(), -1);

        // return miniCut(0, s, dp) - 1;
        int n = s.size();

        vector< int > dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            int miniCost = INT_MAX;
            for(int idx = i; idx < n; idx++){
                if(checkPalindrome(i, idx, s)){
                    int cost = 1 + dp[idx+1];
                    miniCost = min(miniCost, cost);
                }
            }
            dp[i] = miniCost;
        }
        return dp[0] - 1;
    }
};