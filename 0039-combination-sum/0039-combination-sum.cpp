class Solution {
public:
    vector< vector< int >> answer;
    set< vector< int >> st;
    void combination(int sum, int target, vector<int> res, vector<int> &nums){
        if(sum > target) return;
        if(sum == target){
            sort(res.begin(), res.end());
            if(st.find(res) == st.end()){
                st.insert(res);
                answer.push_back(res);
            }
            return;
        }

        for(int i =0; i < nums.size(); i++){
            res.push_back(nums[i]);
            combination(sum + nums[i], target, res, nums);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combination(0, target, {}, candidates);
        return answer;
    }
};