class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // if(sentence.find(searchWord) == string::npos) return -1;
        int idx = 1;
        int size = searchWord.size();
        stringstream ss(sentence);
        string temp;
        while (ss >> temp) {
            if (temp.size() >= size && temp.substr(0, size) == searchWord) {
                return idx;
            } else {
                idx++;
            }
        }
        return -1;
    }
};