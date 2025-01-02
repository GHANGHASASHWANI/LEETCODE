class Solution {
public:
    int maxScore(string s) {
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                zeros++;
            if (s[i] == '1')
                ones++;
        }
        int maximumScore = 0;
        int tempZero = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == '0') {
                tempZero++;
            }
            if (s[i] == '1') {
                ones--;
            }
            maximumScore = max(maximumScore, ones + tempZero);
        }
        return maximumScore;
    }
};