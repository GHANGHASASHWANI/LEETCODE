class Node {
    public:
    Node *links[26] = {NULL};
    bool flag = false;

    bool findWord(char ch) {
        return links[ch - 'a'] != NULL;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    bool isEnd() {
        return flag;
    }
    void setEnd() {
        flag = true;
    }
    void addWord(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.size(); i++) {
            if (not node->findWord(word[i])) {
                node->addWord(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;

        for (int i = 0; i < word.size(); i++) {
            if (not node->findWord(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        if (not node->isEnd()) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (not node->findWord(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */