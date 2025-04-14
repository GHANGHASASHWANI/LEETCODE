class Solution {
private:
    // Count the total distinct ways 
    int countDistinct(const string &s,const  string &t, int idx1, int idx2, vector<vector<int>> &dp){
        if(idx2 == 0) return 1;
        if(idx1 == 0 || idx2 == 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        int countIdx = 0, notCountIdx = 0;
        // If the equal values are encountered
        if(s[idx1 - 1] == t[idx2 - 1]){
            countIdx = countDistinct(s, t, idx1 - 1, idx2 - 1, dp);
        }
        // If the equal values are not encountered
        notCountIdx = countDistinct(s, t, idx1 - 1, idx2, dp);

        return dp[idx1][idx2] = countIdx + notCountIdx;
    }
public:
    int numDistinct(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        vector<vector< double >> dp(len1 + 1, vector<double> (len2 + 1, 0));

        // return countDistinct(s, t, len1 , len2, dp);

        vector< double > prev(len2 +1, 0), curr(len2 + 1, 0);

        prev[0] = curr[0] = 1;

        // for(int i = 0; i < len1; i++){
        //     dp[i][0] = 1;
        // }

        for(int i = 1; i <= len1; i++){
            for(int j = len2; j >= 1; j--){
                if(s[i - 1] == t[j - 1]){
                   prev[j] = prev[j-1] + prev[j];
                }else{
                    prev[j] = prev[j];
                }   
            }
            // prev = curr;
        }

        return (int)prev[len2];

    }
};