class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        while (i < str1.size() && j < str2.size()) {

            int a = (int)str1[i] + 1;
            if (str1[i] == 'z')
                a = 97;
            int b = (int)(str2[j]);

            if (str1[i] == str2[j] || a == b) {

                i++;
                j++;
            } else {
                i++;
            }
        }
        if (j == str2.size()) {
            cout << j;
            return true;
        }
        return false;
    }
};