class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        string ans = "";
        int len = word.size() - numFriends + 1;

        for (int i = 0; i < word.size(); i++) {
            ans = max(ans, word.substr(i, len));
        }
        return ans;
    }
};