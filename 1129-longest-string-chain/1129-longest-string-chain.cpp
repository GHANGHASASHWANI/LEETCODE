class Solution {
private:
    bool compare(string &str1, string &str2){
        if(str1.size() != str2.size() + 1) return false;

        int idx1 =0, idx2 = 0;

        while(idx1 < str1.size()){
            if(idx2 < str2.size() && str1[idx1] == str2[idx2]){
                idx1++;
                idx2++;
            }
            else{
                idx1++;
            }
        }
        if(str1.size() == idx1 && str2.size() == idx2) return true;

        return false;
    }

    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int len1 = words.size();

        vector< int > dp(len1, 1);
        int maxiLen = 1;

        for(int i = 1; i < len1; i++){
            for(int j = 0; j < i; j++){
                if(compare(words[i], words[j]) && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                }
            }
            maxiLen = max(maxiLen, dp[i]);
        }

        return maxiLen;

    }
};