class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string minStr = s;
          for (int i = 0; i < s.size(); i++) {
            char st = s[0];
            s.erase(0, 1);
            s.push_back(st);
            minStr = min(minStr, s);
          }
          return minStr;
        }
        sort(s.begin(), s.end());
        return s;
    }
};