class Solution {
public:
    int possibleStringCount(string word) {
        int answer = 1;

       for (int index = 1; index < word.size(); index++) {
            if (word[index] == word[index - 1]) {
                answer++;
            }
       }

       return answer;
    }
};