class Solution {
public:
    vector<vector< int >> answer;
    void combination(int sum, int target, vector<int> res, vector<int> &nums, int idx){
        if(sum > target) return;

        if(sum == target){
            answer.push_back(res);
            return; 
        }

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            res.push_back(nums[i]);
            combination(sum + nums[i], target, res, nums, i + 1);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combination(0, target, {}, candidates, 0);
        return answer;
    }
};