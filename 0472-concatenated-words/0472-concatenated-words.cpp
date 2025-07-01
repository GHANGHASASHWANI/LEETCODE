class Node {
    public:
    Node *links[26] = {NULL};
    bool flag = false;

    bool findWord(char ch) {
        return links[ch - 'a'] != NULL;
    }
    Node* getWord(char ch) {
        return links[ch - 'a'];
    }
    void setWord(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    bool isEnd() {
        return flag;
    }
    void setEnd() {
        flag = true;
    }
    void removeEnd() {
        flag = false;
    }
};

class TrieNode {
    public:
    unordered_set<string> unique;
    Node* root;

    TrieNode() {
        root = new Node();
    }

    void addWord(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (not node->findWord(word[i])) {
                node->setWord(word[i], new Node());
            }
            node = node->getWord(word[i]);
        }
        node->setEnd();
    }

    // bool dfsCheck(Node* root, string &word, int idx, int count) {
    //     Node* node = root;
    //     int n = word.size();

    //     for (int i = idx; i < word.size(); i++) {
    //         if (not node->findWord(word[i])) return false;
    //         node = node->getWord(word[i]);

    //         if (node->isEnd()) {
    //             if (dfsCheck(word, i + 1, count + 1)) return true;
    //         }
    //     }
    //     return node->isEnd() && count > 1;
    // }

    int dp[100001];

    int concat(int k, string &s) {
        if (k == s.size()) return 0;

        int ans = -1e9;
        if (dp[k] != -1) return dp[k];

        Node* node = root;
        if (not node->findWord(s[k])) return -1e9;

        for (int i = k; i < s.size(); i++) {
            if (not node->findWord(s[i])) return dp[k] = ans;
            node = node->getWord(s[i]);
            if (node->isEnd()) ans = max(ans, 1 + concat(i + 1, s));
        }
        return dp[k] = ans;
    }

    vector<string> allUnique(vector<string> &words) {
        vector<string> ans;

        for (auto &word : words) {
            // if (dfsCheck(word, 0, 0)) {
            //     unique.insert(word);
            // }
            memset(dp, -1, sizeof(dp));
            if (concat(0, word) > 1) {
                unique.insert(word);
            }
        }

        for (auto &word : unique) {
            ans.push_back(word);
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (auto &word : words) {
            root->addWord(word);
        }
        
        vector<string> result = root->allUnique(words);

        return result;
    }
};