class Solution {
public:
    bool isPrefix(string str1, string pref){
        int i =0, j =0;
        while(i < pref.size() && j < str1.size()){
            if(str1[j] != pref[i]){
                return false;
            }
            i++;
            j++;
        }
        return i == pref.size();
    }
    int prefixCount(vector<string>& words, string pref) {
        int answer = 0;
        for(int i =0; i < words.size(); i++){
            if(isPrefix(words[i], pref)) answer++;
        }
        return answer;
    }
};