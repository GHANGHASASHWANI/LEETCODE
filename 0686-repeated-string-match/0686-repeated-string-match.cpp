class Solution {
private:
    void computelps(vector<int> &lps, string &b) {
        int n = b.size();
        int pre = 0, suff = 1;

        while (suff < n) {
            if (b[pre] == b[suff]) {
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
    bool check(vector<int> &lps, string a, string b) {
        int i = 0, j  = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
                if (j == b.size()) {
                    return true;
                }
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        if (a == b) return 1;
        vector<int> lps(b.size(), 0);
        computelps(lps, b);

        // string temp = a;
        int total = 0;

        int n = b.size();
        int m = a.size();

        int need = ceil((n - m)*1.0 / m*1.0) + 1;

        total = need;
        
        string temp = "";

        for (int i = 0; i < need; i++) {
            temp += a;
        }

        // while (temp.size() < b.size() ) {
        //     temp += a;
        //     total++;
        // }

        if (check(lps, temp, b)) return total;

        temp += a;
        if(check(lps, temp, b)) {
            total++;
            return total;
        }
        return -1;
    }
};