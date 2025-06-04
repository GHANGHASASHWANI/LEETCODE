class Solution {
private:
    void createLPS(vector<int> &lps, string str) {
        int n = lps.size();
        int pre = 0, suff = 1;

        while (suff < n) {
            if (str[pre] == str[suff]) {
                lps[suff] = pre + 1;
                pre++;
                suff++;
            } else {
                if (pre == 0) {
                    lps[suff] = 0;
                    suff++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        createLPS(lps, needle);

        int i = 0, j = 0;
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == needle.size()) {
                    return i - j;
                }
            } else {
                if (j == 0) {
                    i++;
                } else {
                     j = lps[j - 1];
                }
            }
        }
        return -1;
    }
};