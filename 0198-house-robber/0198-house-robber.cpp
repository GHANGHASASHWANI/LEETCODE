class Solution {
public:

    int maximumProfit(vector< int > &nums, int index, vector< int > &profit){
        if(index == 0) return nums[0];
        if(index < 0) return 0;

        if(profit[index] != -1) return profit[index];

        int notPick = maximumProfit(nums, index - 1, profit);
        int pick = nums[index] + maximumProfit(nums, index - 2, profit);
        return profit[index] = max(notPick, pick);
    }
    int rob(vector<int>& nums) {
        // int size = nums.size();
        // vector< int > profit(size, -1);
        // int totalProfit = maximumProfit(nums, size -1, profit);
        // return totalProfit;

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