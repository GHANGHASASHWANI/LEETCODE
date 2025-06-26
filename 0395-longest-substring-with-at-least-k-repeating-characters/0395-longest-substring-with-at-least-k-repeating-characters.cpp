class Solution {

private:
    int minFreq (map<char, int> &mpp) {
        int minFreq = INT_MAX;

        for (auto it : mpp) {
            minFreq = min(minFreq, it.second);
        }
        return minFreq;
    }
public:
    int longestSubstring(string s, int k) {
        int n = s.size();

        int length = 0;

        for (int i = 0; i < n ; i++) {
            map<char, int> mpp;
            char minChar = s[i];
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                int mini = minFreq(mpp);
                if (mini >= k) {
                    length = max(length, j - i + 1);
                }
            }
        }
        return length;
    }
};