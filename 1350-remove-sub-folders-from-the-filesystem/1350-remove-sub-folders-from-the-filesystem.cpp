class Node {
public:
    Node* links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(const string& path) {
        Node* node = root;
        for (int i = 0; i < path.size(); ++i) {
            char ch = path[i];
            if (ch == '/') continue;

            if (!node->contains(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    void collect(Node* node, string path, vector<string>& result) {
        if (node->isEnd()) {
            result.push_back(path);
            return; // Stop at first complete path
        }

        for (int i = 0; i < 26; ++i) {
            if (node->links[i]) {
                char ch = 'a' + i;
                collect(node->links[i], path + ch, result);
            }
        }
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> result;
        string prev = "";

        for (const string& f : folder) {
            if (prev.empty() || f.find(prev + "/") != 0) {
                result.push_back(f);
                prev = f;
            }
        }

        return result;
    }
};
