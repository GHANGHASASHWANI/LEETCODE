class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        if(grid.size() == 1 && grid[0].size() == 1) return 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j =0; j < grid[0].size(); j++){
                nums.push_back(grid[i][j]);
              
            }
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int need = nums[n/2];
        // cout<<need<<endl;
        int ans = 0;
        for(int i =0; i < nums.size(); i++){
            // cout<<i<<" "<<ans<<endl;
            if((need - nums[i]) % x != 0) return -1;
            ans += (abs(need - nums[i])/x);
        }
        return ans;
    }
};