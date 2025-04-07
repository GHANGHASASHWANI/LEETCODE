class Solution {
private:
vector<vector< int >> dp;
    bool fn(int sum, int idx, vector<int> &arr, int total){
        if(idx >= arr.size()) return false;
        if(sum == (total - sum)) return true;
        if(dp[idx][sum] != -1) return dp[idx][sum];


        bool ans1 = fn(sum + arr[idx], idx+1, arr, total);
        bool ans2 = fn(sum, idx+1, arr, total);

        return dp[idx][sum] = ans1 || ans2;
    }
public:
    bool canPartition(vector<int>& nums) {
        dp.clear();
        int total = 0;
        for(auto i : nums){
            total += i;
        }
        int n = nums.size();

        dp.resize(n+1, vector< int > (total+1, -1));

        return fn(0, 0, nums, total);
        
    }
};