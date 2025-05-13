class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        unordered_map<char, int> freq;
        for (auto i : s) {
            freq[i]++;
        }
        int mod = 1e9 + 7;
        while (t--) {
            unordered_map<char, int> temp;
            for (auto it : freq){
                char currChar = it.first;
                int currFreq = it.second;
                if (currChar == 'z') {
                    temp['a'] = (temp['a'] + currFreq) % mod;
                    temp['b'] = (temp['b'] +  currFreq) % mod;
                }
                else temp[currChar + 1] = (temp[currChar + 1] + currFreq) % mod;
            }
            freq = temp;
        }
        int answer = 0;

        for (auto it : freq){
            answer = (answer + it.second) % mod;
        }

        return answer;
    }
};