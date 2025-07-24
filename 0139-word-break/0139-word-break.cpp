class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        queue<int> traverse;
        vector<bool> visited(s.size(), false);
        traverse.push(0);

        while (not traverse.empty()) {
            int start = traverse.front();
            traverse.pop();

            if (start == s.length()) return true;

            for (int end = start + 1; end <= s.size(); end++) {
                if (visited[end]) continue;

                if (words.find(s.substr(start, end - start)) != words.end()) {
                    traverse.push(end);
                    visited[end] = true;
                }
            }
        }
        return false;
    }
};