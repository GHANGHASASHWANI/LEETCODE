class Solution {
private:
    int dp[12][2][12];

    int fn(string &str, int idx, int tight, int cnt){
        if(idx == str.size()) return cnt;
        if(dp[idx][tight][cnt] != -1) return dp[idx][tight][cnt];
        
        int limit = (tight == 1 ? str[idx] - '0' : 9);
        int ans = 0;
        for(int i =0; i <= limit; i++){
            int updatedCnt = cnt + (i == 1 ? 1 : 0);
            ans += fn(str, idx+1, tight & (i == str[idx] - '0'), updatedCnt);
        }
        return dp[idx][tight][cnt] = ans;
    }
public:
    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        string str =to_string(n);
        return fn(str, 0, 1, 0);
    }
};