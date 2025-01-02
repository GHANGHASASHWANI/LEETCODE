class Solution {
public:
    vector<int> vowelStrings(vector<string>& word,
                             vector<vector<int>>& queries) {
        set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int n = word.size();
        vector<int> answer(n, 0);
        for (int i = 0; i < word.size(); i++) {
            char need1 = word[i][0];
            char need2 = word[i][word[i].size() - 1];
            if (vowels.find(need1) != vowels.end() &&
                vowels.find(need2) != vowels.end()) {
                answer[i] = 1;
            }
        }

        for (int i = 1; i < answer.size(); i++) {
            answer[i] = answer[i] + answer[i - 1];
        }

        vector<int> result;

        for (int i = 0; i < queries.size(); i++) {
            int index1 = queries[i][0];
            int index2 = queries[i][1];

            int output =
                answer[index2] - (index1 == 0 ? 0 : answer[index1 - 1]);

            result.push_back(output);
        }
        return result;
    }
};