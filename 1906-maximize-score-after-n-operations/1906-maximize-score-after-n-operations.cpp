class Solution {
private:
    unordered_map< vector<bool>, int > dp;
    int fn(vector< int> &nums, vector< bool> &vis, int op){
        if(dp.find(vis) != dp.end()) return dp[vis];
        int ans = 0;
        for(int i =0; i < nums.size()-1; i++){
            if(vis[i]) continue;
            for(int j = i+1; j < nums.size(); j++){
                if(vis[j]) continue;
                int gcdd = op * __gcd(nums[i], nums[j]);
                vis[i] = true;
                vis[j] =  true;
                int rem = fn(nums, vis, op+1);
                vis[i] = false;
                vis[j] = false;
                ans = max(ans, gcdd + rem);
            }
        }
        return dp[vis] = ans;
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector< bool > vis(n, false);
        return fn(nums, vis, 1);
    }
};