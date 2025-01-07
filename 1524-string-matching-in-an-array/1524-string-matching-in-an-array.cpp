class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector< string > answer;
        set < string > temp;
        for(int i =0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(words[j].find(words[i]) != string :: npos && i != j && temp.find(words[i]) == temp.end()){
                    answer.push_back(words[i]);
                    temp.insert(words[i]);
                }
            }
        }
        return answer;
    }
};