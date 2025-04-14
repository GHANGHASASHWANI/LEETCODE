class Solution {
private:
    int commonSubsequence(string &word1, int index1, string &word2, int index2){
        if(index1 < 0 or index2 < 0) return 0;

        int totalCommon = 0;

        if(word1[index1] == word2[index2]){
            totalCommon = 1 + commonSubsequence(word1, index1 - 1, word2, index2 - 1);
        }
        else {
            int word1Sequence = commonSubsequence(word1, index1 - 1, word2, index2);
            int word2Sequence = commonSubsequence(word1, index1, word2, index2 - 1);

            totalCommon = max(word1Sequence, word2Sequence);
        }
        return totalCommon;
    }
public:
    int minDistance(string word1, string word2) {
        // int size1 = word1.size(), size2 = word2.size();

        // int longestCommon = commonSubsequence(word1, size1 - 1, word2, size2 -1);

        // return size1 + size2 - 2 * longestCommon;

        int n = word1.size(), m = word2.size();

        vector<vector< int >> dp(n+1, vector<int> (m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        int longSubseq = dp[n][m];

        return (n - longSubseq) + (m - longSubseq);
    }
};