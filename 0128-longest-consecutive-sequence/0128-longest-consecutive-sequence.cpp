class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mpp;

        int length = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (!mpp[nums[i]]) {
                mpp[nums[i]] = mpp[nums[i] - 1] + mpp[nums[i] + 1] + 1;
                mpp[nums[i] - mpp[nums[i] - 1]] = mpp[nums[i]];
                mpp[nums[i] + mpp[nums[i] + 1]] = mpp[nums[i]];

                length = max(length, mpp[nums[i]]);
            }
        }
        return length;
    }
};