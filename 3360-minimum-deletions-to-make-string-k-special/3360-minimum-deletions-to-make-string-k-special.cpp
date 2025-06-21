class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char, int> freq;

        for (auto& it : word) {
            freq[it]++;
        }

        int ans = INT_MAX;

        for (auto& it : freq) {
            int currTotal = 0;

            for (auto& jt : freq) {
                if (it.first != jt.first) {
                    if ((jt.second > it.second) &&
                        (jt.second - it.second) > k) {
                        currTotal += abs(jt.second - k - it.second);
                    } else if (jt.second < it.second) {
                        currTotal += jt.second;
                    }
                }
            }
            ans = min(ans, currTotal);
        }

        return ans;
    }
};