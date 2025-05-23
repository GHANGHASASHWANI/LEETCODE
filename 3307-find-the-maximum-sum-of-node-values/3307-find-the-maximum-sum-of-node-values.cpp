class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int minLoss = INT_MAX;
        int gainCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int xk = x ^ k;
            if (xk > x) {
                gainCount++;
                sum += xk;
                minLoss = min(minLoss, xk - x);
            } else {
                sum += x;
                minLoss = min(minLoss, x - xk);
            }
        }

        if (gainCount % 2 != 0) {
            sum -= minLoss;
        }

        return sum;
    }
};
