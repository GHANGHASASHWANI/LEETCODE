class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int idx, vector<int> subset,
               int target) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }
        if (idx == candidates.size()) {
            return;
        }

        if (target >= candidates[idx]) {
            subset.push_back(candidates[idx]);
            solve(candidates, idx + 1, subset, target - candidates[idx]);
            subset.pop_back();
        }

        int j = idx + 1;
        while (j < candidates.size() && candidates[j] == candidates[j - 1])
            j++;
        solve(candidates, j, subset, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, {}, target);
        return ans;
    }
};