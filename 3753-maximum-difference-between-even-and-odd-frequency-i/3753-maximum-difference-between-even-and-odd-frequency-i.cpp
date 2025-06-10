class Solution {
public:
    int maxDifference(string s) {
        int odd = 0, even = INT_MAX;

        map<char, int> mpp;

        for (auto &it : s) {
            mpp[it]++;
        }

        for (auto &it : mpp) {
            if (it.second % 2 == 0) {
                even = min(even, it.second);
            } else {
                odd = max(odd, it.second);
            }
        }
        return odd - even;
    }
};