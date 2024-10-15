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
        int size = nums.size();
        vector< int > profit(size, -1);
        int totalProfit = maximumProfit(nums, size -1, profit);
        return totalProfit;
    }
};