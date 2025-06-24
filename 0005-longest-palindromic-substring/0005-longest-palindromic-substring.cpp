class Solution {
private:
    bool isPalindrome(string &s) {
        int size = s.size();
        for (int i = 0; i < size / 2; i++) {
            if (s[i] != s[size - 1 - i]) return false;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string ans = "";

        for (int  i =0; i < s.size(); i++) {
            string temp = "";
            for (int j = i; j < s.size(); j++) {
                temp += s[j];
                if (temp.size() > ans.size() && isPalindrome(temp)) {
                    ans = temp;
                }
            }
        }
        return ans;
    }
};