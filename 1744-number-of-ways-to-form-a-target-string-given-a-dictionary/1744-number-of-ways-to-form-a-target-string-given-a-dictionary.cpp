class Solution {
private:
    // int fn(int i, int j, int kth, vector<string>&s, string t){
    //     if(j == t.size()) return 1;
    //     if(i >= s.size() || kth >= s[0].size() || j >= t.size()){
    //         return 0;
    //     }

    //     int ans = fn(i+1, j, kth, s, t);

    //     for(int k = kth; k < s[i].size(); k++){
    //         if(s[i][k] == t[j]){
    //             ans += fn(0, j+1, k+1, s, t);
    //             j++;
    //         }
    //     }
    //     return ans;
    // }

    // vector<vector< int >> dp;
    int mod = 1e9 + 7;
    // int fn(int i, int j, vector< unordered_map< char, int>> &fq, string &t, vector<string> &words){
    //     if(i >= t.size()) return 1;
    //     if(j >= words[0].size()) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];


    //     int notTake = fn(i, j+1, fq, t, words);

    //     int take =(1LL*fq[j][t[i]] * fn(i+1, j+1, fq, t, words))%mod;

    //     return dp[i][j] = (notTake % mod + take%mod)%mod;
    // }


public:
    int numWays(vector<string>& words, string target) {
        vector< unordered_map< char, int >> fq(words[0].size());

        for(int i =0; i < words.size(); i++){
            for(int j = 0; j <words[i].size(); j++){
                fq[j][words[i][j]]++;
            }
        }

        // dp.clear();
        // dp.resize(target.size()+1, vector<int> (words[0].size() +1, -1));

        // return fn(0, 0, fq, target, words);

        vector<vector<int>> dp(target.size()+1, vector<int> (words[0].size() +1, 0));

        for (int j = 0; j <= words[0].size(); j++) {
            dp[target.size()][j] = 1;
        }

        for(int i = target.size()-1; i >= 0; i--){
            for(int j = words[0].size()-1; j >= 0; j--){
                int notTake = dp[i][j+1];
                int take =(1LL*fq[j][target[i]] * dp[i+1][j+1])%mod;
                dp[i][j] = (notTake + take)%mod;
            }
        }

        return dp[0][0];
    }
};