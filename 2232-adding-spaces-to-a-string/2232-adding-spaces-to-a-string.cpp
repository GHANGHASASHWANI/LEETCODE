class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";

        int j = 0;
        if(spaces[j] == 0){
            result+= " ";
            j++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (j != spaces.size() && i == spaces[j] - 1 ) {
                result += s[i];
                result += " ";
                j++;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};