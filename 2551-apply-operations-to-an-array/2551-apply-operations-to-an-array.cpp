class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i =1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                nums[i-1]*=2;
                nums[i] = 0;
            }
        }
        int zeros = 0;
        vector< int > ans;
        for(int i =0; i < nums.size(); i++){
            if(nums[i] == 0) zeros++;
            else{
                ans.push_back(nums[i]);
            }
        }
        while(zeros--){
            ans.push_back(0);
        }
        return ans;
    }
};