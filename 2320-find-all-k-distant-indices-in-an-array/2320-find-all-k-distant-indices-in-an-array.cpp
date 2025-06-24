class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> index;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (abs(i - j) <= k && nums[j] == key) {
                    index.push_back(i);
                    break;
                }
            }
        }
        sort(index.begin(), index.end());

        return index;
    }
};