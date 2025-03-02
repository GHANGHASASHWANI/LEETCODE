class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        map<int, int> mpp;

        for (auto itr : nums1) {
            mpp[itr[0]] += itr[1];
        }
        for (auto itr : nums2) {
            mpp[itr[0]] += itr[1];
        }
        vector<vector<int>> ans;
        for (auto j : mpp) {
            ans.push_back({j.first, j.second});
        }
        return ans;
    }
};