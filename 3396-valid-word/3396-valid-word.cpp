class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    bool isValid(string word) {
        if (word.size() < 3) return false;

        int vowel = 0, cons = 0;

        for (int  i =0; i < word.size(); i++) {
            char currChar = word[i];
            if ((currChar >= 'a' && currChar <='z') || (currChar >= 'A' && currChar <='Z')) {
                if (isVowel(currChar)) {
                    vowel++;
                } else {
                    cons++;
                }
            } else if ((currChar >= '0' && currChar <='9')) {
                continue;
            }
             else {
                return false;
            }
        }
        return vowel && cons;
    }
};