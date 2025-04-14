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
        int len1 = s.size(), len2 = p.size();
        vector<vector< int >> dp(len1 + 1, vector< int > (len2 + 1, -1));
        return checkString(s, len1, p, len2, dp);
    }
};