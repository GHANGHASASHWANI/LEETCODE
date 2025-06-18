class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int z) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;

        for (int i =  0; i < nums.size(); i++) {
            int need  = 3;
            vector<int> ans;
            ans.push_back(nums[i]);
            
            for (int k = i + 1; k < i + need; k++) {
                ans.push_back(nums[k]);
            }
            if (ans[2] - ans[0] > z) return {};
            i += need - 1;
            answer.push_back(ans);
        }
        return answer;
    }
};