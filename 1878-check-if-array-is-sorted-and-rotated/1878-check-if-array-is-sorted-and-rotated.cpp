class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]) ans++;
        }
        if(nums[0] < nums[nums.size() - 1]) ans++;
        return ans <= 1;
    }
};