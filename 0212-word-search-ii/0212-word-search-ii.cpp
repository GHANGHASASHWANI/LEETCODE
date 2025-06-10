class Node {
    public:
    Node *links[26] = {NULL};
    bool flag = false;

    bool findWord(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void setWord(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    bool isEnd() {
        return flag;
    }
    void setEnd() {
        flag = true;
    }
};
class Trie {
    private: Node *root;
    public:
    Trie () {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for (int i = 0; i < word.size(); i++) {
            if (not node->findWord(word[i])) {
                node->setWord(word[i], new Node());
            } 
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    set<string> ans;
    void searchWord(int row, int col, vector<vector<char>> &board, Node* node, string temp, vector<vector<bool>> &visited) {

        if (node->isEnd()) {
            ans.insert(temp);
        }
        visited[row][col] = true;
        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int newRow = row + rows[i];
                int newCol = col + cols[i];
                if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() && not visited[newRow][newCol]) {
                    
                    if (node->findWord(board[newRow][newCol])) {
                            Node* newNode = node->get(board[newRow][newCol]);
                    searchWord(newRow, newCol, board, newNode, temp + board[newRow][newCol], visited);
                    }
                    
                }
            }
        visited[row][col] = false;
    }

    set<string> check(vector<vector<char>> &board) {
        Node* node = root;
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size() , false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (node->findWord(board[i][j])) {
                    string temp = "" ;
                    temp += (board[i][j]);
                    Node* newNode = node->get(board[i][j]);
                    searchWord(i, j, board,  newNode, temp, visited);  
                }
            }
        }
        return ans;
    }
    
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tree;

        for (int i = 0; i < words.size(); i++) {
            tree.addWord(words[i]);
        }
        set<string> res = tree.check(board);

        vector<string> ans(res.begin(), res.end());

        return ans;
    }
};