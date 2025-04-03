class Solution {
private:
    vector<vector< int >> dp;
    int fn(int curr, char prev, string &s){
        if(curr >= s.size()) return 0;

        if(dp[curr][prev - '0'] != -1) return dp[curr][prev - '0'];

        int flip = INT_MAX, nonFlip = INT_MAX;

        if(s[curr] == '1'){
            if(prev == '0'){
                flip = 1 + fn(curr+1, '0', s);
                nonFlip = fn(curr+1, '1', s);
            }else{
                nonFlip = fn(curr+1, '1', s);
            }
        }else{
            if(prev == '0'){
                flip = 1 + fn(curr+1, '1', s);
                nonFlip = fn(curr+1, '0', s);
            }else{
                flip = 1 + fn(curr+1, '1', s);
            }
        }
        return dp[curr][prev - '0'] = min(flip, nonFlip);
    }
public:
    // int minFlipsMonoIncr(string s) {
    //     int n = s.size();
    //     dp.clear();
    //     dp.resize(n+1, vector<int> (2, -1));
    //     return fn(0, '0', s);
    // }
    int minFlipsMonoIncr(string s) {
        int ones = 0, flips = 0;
        for(int i =0; i < s.size(); i++){
            if(s[i] == '1') ones++;
            else flips++;
            flips = min(flips, ones);
        }
        return flips;
    }
};