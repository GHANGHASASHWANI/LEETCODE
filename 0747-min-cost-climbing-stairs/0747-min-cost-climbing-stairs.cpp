class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        for(int index = 2; index < cost.size(); index++){
            cost[index] += min(cost[index - 1] , cost[index - 2]);
        }
        return min(cost[size - 1], cost[size - 2]);
    }
};