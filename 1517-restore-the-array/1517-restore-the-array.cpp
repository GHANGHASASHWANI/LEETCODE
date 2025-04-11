class Solution {
private:
    vector< int > dp;
    int mod = 1e9 + 7;
    int fn(int idx, int n, string &str, int k){
        if(idx >= n) return 1;
        if(str[idx] == '0') return 0;

        if(dp[idx] != -1) return dp[idx];

        long ans = 0;
        long long num = 0;
        for(int i = idx; i < str.size(); i++){
            num = (num*10) + (str[i] - '0');
            if(num > k) break;
            // cout<<num<<endl;
            ans += fn(i+1, n, str, k);
        }
        return dp[idx] = (ans)%mod;
    }
public:
    int numberOfArrays(string s, int k) {
        dp.clear();
        dp.resize(s.size()+1, -1);
        return fn(0, s.size(),s, k);
    }
};