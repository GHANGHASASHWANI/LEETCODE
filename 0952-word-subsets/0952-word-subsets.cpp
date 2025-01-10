class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector< string > answer;

        map< char, int> maxFreq;

        for(int i =0; i < words2.size(); i++){
            map< char, int> curr;
            for(int j = 0; j < words2[i].size();j++){
                curr[words2[i][j]]++;
            }
            for(auto j : curr){
                if(j.second > maxFreq[j.first]){
                    maxFreq[j.first] = j.second;
                }
            }
        }
    
        for(int i =0; i < words1.size(); i++){
            map<char, int> curr;
            for(int j =0; j < words1[i].size(); j++){
                curr[words1[i][j]]++;
            }
            bool check = true;
            for(auto j : maxFreq){
                if(curr[j.first] < maxFreq[j.first]){
                    check = false;
                    break;
                }
            }
            if(check){
                answer.push_back(words1[i]);
            }
        }
        return answer;
    }
};