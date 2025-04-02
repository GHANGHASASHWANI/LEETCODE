class Solution {
public:

    int rob(vector<int>& nums) {

        int size = nums.size();
        if(size == 1) return nums[0];
        vector< int > profit(size, 0);
        profit[0] = nums[0];
        profit[1] = max(nums[0], nums[1]);

        for(int index = 2; index < size; index ++){
            int notPick = profit[index -1];
            int pick = nums[index] + profit[index - 2];
            profit[index] = max(notPick, pick);
        }
        return profit[size - 1];
    }
};