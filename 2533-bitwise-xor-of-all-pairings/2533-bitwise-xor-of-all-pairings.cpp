class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        map<int, long> mp;

        for (auto i : nums1) {
            mp[i] += len2;
        }
        for (auto i : nums2) {
            mp[i] += len1;
        }
        int ans = 0;
        for (auto i : mp) {
            if (i.second % 2 == 1) {
                ans ^= i.first;
            }
        }
        return ans;
    }
};