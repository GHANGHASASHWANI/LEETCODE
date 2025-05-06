class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even = 0;

        for(int i =0; i < nums.size(); i++){
            int length = log10(nums[i]) + 1;
            if(length % 2 == 0) even++;
        }
        return even;
    }
};