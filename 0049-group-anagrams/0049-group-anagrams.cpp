#pragma GCC optimize("O3", "unroll-loops")
int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> values;
        vector<vector<string>> groupAnagrams;
        for (int index = 0; index < strs.size(); index++) {
            string dummy = strs[index];
            sort(dummy.begin(), dummy.end());
            values[dummy].push_back(strs[index]);
        }
        for (auto anagram : values) {
            groupAnagrams.push_back(anagram.second);
        }
        return groupAnagrams;
    }
};
