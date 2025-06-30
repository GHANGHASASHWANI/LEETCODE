class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mpp;

        for (auto it : nums) {
            mpp[it]++;
        }

        int ans = 0;

        for (auto it = next(mpp.begin()); it != mpp.end(); it++) {
            if (abs(it->first - prev(it)->first) == 1) {
                ans = max(ans, it->second + prev(it)->second);
            }
        }
        return ans;
    }
};