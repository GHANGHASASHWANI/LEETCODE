class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> ans(numRows);

        for (int i = 0; i < s.size();) {
            for (int j = 0; j < numRows && i < s.size(); j++) {
                ans[j].push_back(s[i]);
                i++;
            }
           
            int need = numRows - 2;
            int lastRow = ans.size() - 2;
            while (need && i < s.size() && lastRow >= 0) {
                // cout<<lastRow<<" "<<s[i]<<endl;

                ans[lastRow].push_back(s[i]);
                lastRow--;
                need--;
                i++;
               
            }
        }
        string res = "";

        for (auto it : ans) {
            for (auto jt : it) {
                res += jt;
            }
        }
        return res;
    }
};