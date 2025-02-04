class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int tempSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                tempSum += nums[i];
            }else{
                sum = max(sum, tempSum);
                tempSum = nums[i];
            }
        }
        sum = max(sum, tempSum);
        return sum;
    }
};