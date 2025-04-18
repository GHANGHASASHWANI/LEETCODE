class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end()) return 0;
        if(words.find(beginWord) != words.end()){
            words.erase(beginWord);
        }
        queue<pair<string, int>> queueWord;
        queueWord.push({beginWord, 1});

        while(not queueWord.empty()){
            string currWord = queueWord.front().first;
            int currCount = queueWord.front().second;
            queueWord.pop();

            if(currWord == endWord) return currCount;

            for(int i =0; i < currWord.size(); i++){
                string tempWord = currWord;
                for(int j = 0; j < 26; j++){
                    tempWord[i] = char('a' + j);
                    if(words.find(tempWord) != words.end()){
                        queueWord.push({tempWord, currCount + 1});
                        words.erase(tempWord);
                    }
                }
            }
        }
        return 0;
    }
};