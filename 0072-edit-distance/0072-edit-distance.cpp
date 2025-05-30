class Solution {
private:
    int findDistance(int idx1, const string &word1, int idx2, const string &word2, vector<vector< int >> &dp){
        if(idx1 == 0 ) return idx2;
        if(idx2 == 0) return idx1;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(word1[idx1 - 1] == word2[idx2 - 1]){
            return findDistance(idx1 - 1, word1, idx2 - 1, word2, dp);
        }

        int insertVal = 1 + findDistance(idx1, word1, idx2 -  1, word2, dp);
        int deleteVal = 1 + findDistance(idx1 - 1, word1, idx2, word2, dp);
        int replaceVal = 1 + findDistance(idx1 - 1, word1, idx2 -  1, word2, dp);

        return min({insertVal, deleteVal, replaceVal});
    }
public:
    int minDistance(string word1, string word2) {
        // int len1 = word1.size(), len2 = word2.size();
        // vector<vector< int >> dp(len1 + 1, vector< int > (len2 + 1, -1));
        // return findDistance(len1, word1, len2, word2, dp);

        int len1 = word1.size(), len2 = word2.size();

        vector<vector< int >> dp(len1 + 1, vector< int > (len2 + 1, 0));

        for(int i =0; i <= len1; i++){
            dp[i][0] = i;
        }
        for(int j =0; j <= len2; j++){
            dp[0][j] = j;
        }

        for(int i =1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int replaceVal = 1 + dp[i - 1][j - 1];
                    int deleteVal = 1 + dp[i - 1][j];
                    int insertVal = 1 + dp[i][j - 1];

                    dp[i][j] = min({replaceVal, deleteVal, insertVal});
                }
            }
        }
        return dp[len1][len2];
    }
};