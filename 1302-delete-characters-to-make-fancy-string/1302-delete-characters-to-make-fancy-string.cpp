class Solution {
public:
    string makeFancyString(string s) {
        string res = "" ;
        res += (s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] && s[i] == s[i + 1]) {
                continue;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};