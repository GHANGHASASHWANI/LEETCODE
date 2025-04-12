class Solution {
private:
vector< int > dp;
int fn(vector<int> &stone, int idx){
    if(idx >= stone.size()) return 0;
    if(dp[idx] != -1) return dp[idx];

    int sum = 0, maxDiff = INT_MIN;

    for(int i = idx; i < min((int)stone.size(), idx + 3); i++){
        sum += stone[i];
       int opponent = fn(stone, i+1);
       maxDiff = max(maxDiff, sum - opponent);
    }

    return dp[idx] = maxDiff;
}
public:
    string stoneGameIII(vector<int>& stoneValue) {
        dp.clear();
        dp.resize(stoneValue.size()+1, -1);

        int k = fn(stoneValue, 0);
        if(k < 0) return "Bob";
        if(k > 0) return "Alice";
        return "Tie";
    }
};