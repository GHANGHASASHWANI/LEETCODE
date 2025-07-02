class Node {
    public:
        Node* links[26] = {NULL};
        bool flag = false;

        bool findWord(char word) {
            return links[word - 'a'] != NULL;
        }
        Node* getWord(char word) {
            return links[word - 'a'];
        }
        void setWord(char word, Node *node) {
            links[word - 'a'] = node;
        }
        bool isEnd() {
            return flag;
        }
        void setEnd() {
            flag = true;
        }
};
class TrieNode {
    private:
        Node* root;
    public:
        TrieNode() {
            root = new Node();
        }

        void addWord(string &word) {
            Node* node = root;

            for (int index = 0; index < word.size(); index++) {
                char currWord = word[index];

                if (not node->findWord(currWord)) {
                    node->setWord(currWord, new Node());
                }
                node = node->getWord(currWord);
            }
            node->setEnd();
        }

        int dp[100001];

        int searchWord(string &word, int start) {
            if (start == word.size()) return 0;

            if (dp[start] != -1) return dp[start];

            Node* node = root;

            int ans = 1e6;

            for (int index = start; index < word.size(); index++) {
                if (node->findWord(word[index])) {
                    ans = min(ans, 1 + searchWord(word, index + 1));
                    node = node->getWord(word[index]);
                } else {
                    break;
                }
            }
            return dp[start] = ans;
        }
};
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        TrieNode prefix;

        for (auto &word : words) {
            prefix.addWord(word);
        }

        memset(prefix.dp, -1, sizeof(prefix.dp));

        int count = prefix.searchWord(target, 0);
        

        return count == 1e6 ? -1 : count;
    }
};