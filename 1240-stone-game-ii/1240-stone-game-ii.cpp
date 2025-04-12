class Solution {
private:
    int dp[2][101][101];
    int fn(vector<int> &piles, int p, int i, int m){
        if(i >= piles.size()) return 0;

        if(dp[p][i][m] != -1) return dp[p][i][m];

        int result = (p == 1 ? -1 : INT_MAX);
        int stone = 0;

        for(int x = 1; x <= min(2*m, (int)piles.size() -i); x++){
            stone += piles[i + x - 1];
            if(p == 1){
                result = max(result, stone + fn(piles, 0, i+x, max(m,x)));
                // cout<<result<<" "<<endl;
            }else{
                result = min(result, fn(piles, 1, i + x, max(m,x)));
            }
        }
        return dp[p][i][m] = result;
    }
public:
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return fn(piles, 1, 0, 1);
    }
};