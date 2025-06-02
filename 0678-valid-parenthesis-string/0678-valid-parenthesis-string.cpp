class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = max(0, low - 1);
                high--;
            } else { // '*'
                low = max(0, low - 1); // use * as ')'
                high++; // use * as '('
            }
            if (high < 0) return false; // too many ')'
        }
        return low == 0;
    }
};
