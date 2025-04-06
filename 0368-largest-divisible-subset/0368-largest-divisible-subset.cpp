class Solution {
// private:
//     vector<int> res;
//     map< int, vector<int>> dp;
//     void fn(vector<int> &nums, int idx, vector<int> ans, int prev){
//         if(idx >= nums.size()){
//             if(ans.size() > res.size()) res = ans;
//             return;
//         }

//         if(dp.find(idx) != dp.end()){
//             if(dp[idx].size() > res.size()){
//                 res = dp[idx];
//                 return;
//             }
//         }

//         fn(nums, idx+1, ans, prev);

//         if(nums[idx] % prev == 0 || prev % nums[idx] == 0){
//             ans.push_back(nums[idx]);
//             fn(nums, idx+1, ans, nums[idx]);
//             ans.pop_back();
//         }

//         dp[idx] = ans;
//     }
public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         vector<int> ans;
//         sort(nums.rbegin(), nums.rend());
//         fn(nums, 0,ans, 1);

//         return res;
//     }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector< int >> dp(nums.size());

        for(int i = nums.size() - 1; i >= 0; i--){
            dp[i] = {nums[i]};
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0){
                    vector<int> temp = dp[j];
                    temp.push_back(nums[i]);
                    if(temp.size() > dp[i].size()){
                        dp[i] = temp;
                    }
                }
            }
        }
        vector< int > ans;

        for(auto i : dp){
            if(i.size() > ans.size()) ans = i;
        }
        return ans;
    }
};