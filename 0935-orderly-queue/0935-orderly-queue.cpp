class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
           string minStr = s;
           for (int i = 0; i < s.size(); i++) {
            minStr = min(minStr, s.substr(i) + s.substr(0, i));
           }
           return minStr;
        }
        sort(s.begin(), s.end());
        return s;
    }
};