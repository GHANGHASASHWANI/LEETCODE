class Solution {
private:
    bool checkString(const string &s, int idx1, const string &p, int idx2, vector<vector< int >> &dp){
        if(idx2 == 0 && idx1 == 0) return true;
        if(idx1 != 0 && idx2 == 0) return false;
        if(idx2 != 0 && idx1 == 0){
            for(int j = 0; j < idx2; j++){
                if(p[j] != '*') return false;
            }
            return true;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        bool isSame = false;
        if(s[idx1 - 1] == p[idx2 - 1]){
            isSame = checkString(s, idx1 - 1, p, idx2 - 1, dp);
        }
        else if(p[idx2 - 1] == '?'){
            isSame = checkString(s, idx1 - 1, p, idx2 - 1, dp);
        }
        else if(p[idx2 - 1] == '*'){
            bool skipOne = checkString(s, idx1 , p, idx2 - 1, dp);
            bool skipMany = checkString(s, idx1 - 1, p, idx2, dp);

            isSame = skipOne || skipMany;
        }

        return dp[idx1][idx2] = isSame;
    }
public:
    bool isMatch(string s, string p) {
        // int len1 = s.size(), len2 = p.size();
        // vector<vector< int >> dp(len1 + 1, vector< int > (len2 + 1, -1));
        // return checkString(s, len1, p, len2, dp);

        int len1 = s.size(), len2 = p.size();
        vector<vector< bool >> dp(len1 + 1, vector< bool > (len2 + 1, false));
        dp[0][0] = true;

        for(int i =1; i <= len1; i++){
            dp[i][0] = false;
        }
        for(int i =0; i <= len2; i++){
            int flag = true;
            for(int j = 1; j <= i; j++){
                if(p[j -1 ] != '*'){
                    flag = false;
                    break;
                }
            }
           dp[0][i] = flag;
        }

        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                bool isSame = false;
                if(s[i-1] == p[j - 1]){
                    isSame = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '?'){
                    isSame = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    isSame = dp[i - 1][j] || dp[i][j - 1];
                }
                dp[i][j] = isSame;
            }
        }
        return dp[len1][len2];
    }
};