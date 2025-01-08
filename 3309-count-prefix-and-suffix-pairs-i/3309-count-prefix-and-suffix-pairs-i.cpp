class Solution {
public:
    bool isPrefixSuffix(string str1, string str2) {
        bool answer1 = true;
        int index1 = 0, index2 = 0;
        while (index1 < str1.size()) {
            if (str1[index1] != str2[index2]) {
                answer1 = false;
                break;
            }
            index1++;
            index2++;
        }
        bool answer2 = true;
        int index3 = str1.size() - 1, index4 = str2.size() - 1;
        while (index3 >= 0) {
            if (str1[index3] != str2[index4]) {
                answer2 = false;
                break;
            }
            index3--, index4--;
        }
        return answer1 && answer2;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int total = 0;

        for (int index1 = 0; index1 < words.size(); index1++) {
            for (int index2 = index1 + 1; index2 < words.size(); index2++) {
                if (words[index1].size() <= words[index2].size() &&
                    isPrefixSuffix(words[index1], words[index2])) {
                    total++;
                }
            }
        }
        return total;
    }
};