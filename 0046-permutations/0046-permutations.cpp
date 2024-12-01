class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> temp){
        if(nums.size()==0){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i < nums.size(); i++){
            int ele = nums[i];
            nums.erase(nums.begin()+i);
            temp.push_back(ele);
            solve(nums,temp);
            temp.pop_back();
            nums.insert(nums.begin()+i, ele);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, {});
        return ans;
    }
};