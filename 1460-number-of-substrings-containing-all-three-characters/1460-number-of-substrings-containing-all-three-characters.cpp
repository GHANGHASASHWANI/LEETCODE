class Solution {
public:
    int numberOfSubstrings(string s) {
        map< char, int > mp;
        int i =0, j =0, result = 0;
        while(j < s.size()){
            int ch = s[j];
            mp[ch]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                result += s.size() - j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return result;
    }
};