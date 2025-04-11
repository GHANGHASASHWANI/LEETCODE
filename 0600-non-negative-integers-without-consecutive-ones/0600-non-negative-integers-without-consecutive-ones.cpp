class Solution {
private:
    string str;
    int dp[30][2][2];
    int fn(int idx, bool tight, bool prev){
        if(idx == str.size()) return 1;
        if(dp[idx][tight][prev] != -1) return dp[idx][tight][prev];

        int ans = 0, limit = (tight ? str[idx] - '0' : 1);

        for(int i =0; i <= limit; i++){
            if(i == 1 && prev) return ans;
            else{
                ans += fn(idx+1, tight && (i == str[idx] - '0'), i == 1);
            }
        }
        return dp[idx][tight][prev] = ans;
    }
public:
    int findIntegers(int n) {
        memset(dp, -1, sizeof(dp));
        while(n > 0){
            int rem = n % 2;
            n /= 2;
            str.push_back((char)rem + '0');
        }
        reverse(str.begin(), str.end());
        return fn(0, 1, 0);
    }
};