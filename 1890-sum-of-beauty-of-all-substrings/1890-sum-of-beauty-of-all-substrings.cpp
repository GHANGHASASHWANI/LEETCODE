class Solution {
private:
    int findBeauty(map<char, int> &mpp) {
        int miniFreq = INT_MAX, maxFreq = INT_MIN;

        for (auto &it : mpp) {
            miniFreq = min(miniFreq, it.second);
            maxFreq = max(maxFreq, it.second);
        }
        return maxFreq - miniFreq;
    }
public:
    int beautySum(string s) {
        int beauty = 0;

        for (int i = 0; i < s.size(); i++) {
            map<char, int> mpp;

            for (int j = i; j < s.size(); j++) {
                mpp[s[j]]++;

                int result = findBeauty(mpp);
                // cout<<result<<endl;
                beauty += result;
            }
        }
        return beauty;
    }
};