class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        unordered_map<char, int> word1Frequency;
        unordered_map<char, int> word2Frequency;

        for(int index = 0; index < word1.size(); index++){
            word1Frequency[word1[index]]++;
        }

        for(int index = 0; index < word2.size(); index++){
            word2Frequency[word2[index]]++;
        }

        unordered_map<int, int> frequency1;
        unordered_map<int, int> frequency2;

        for(auto word : word1Frequency){
            if(word2Frequency.find(word.first) == word2Frequency.end()){
                return false;
            }
            frequency1[word.second]++;
        }
        for(auto word : word2Frequency){
            if(word1Frequency.find(word.first) == word1Frequency.end()){
                return false;
            }
            frequency2[word.second]++;
        }

        for(auto freq1 : frequency1){
            if(frequency2.find(freq1.first) == frequency2.end()){
               return false;
            }
            if(freq1.second != frequency2[freq1.first]){
                return false;
            }
        }
        return true;
    }
};