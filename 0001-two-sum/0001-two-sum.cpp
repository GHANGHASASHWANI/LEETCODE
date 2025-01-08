class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map< int, int> values;
        for(int index = 0; index < nums.size(); index++){
            int required = target - nums[index];
            if(values.find(required) != values.end()){
                return {index, values[required]};
            }
            values.insert({nums[index], index});
        }
        return {};
    }
};