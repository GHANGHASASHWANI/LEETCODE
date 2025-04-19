class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long totalPairs = 0;
        sort(nums.begin(), nums.end());
        int len = nums.size();

        for(int i = 0; i < len; i++){
            int lowerFind = lower - nums[i];
            int lowerIdx = lower_bound(nums.begin() + i + 1, nums.end(), lowerFind) - nums.begin();
            int upperFind = upper - nums[i];
            int upperIdx = upper_bound(nums.begin() + i + 1, nums.end(), upperFind) - nums.begin();

            totalPairs += (upperIdx - lowerIdx);
        }

        return totalPairs;
    }
};