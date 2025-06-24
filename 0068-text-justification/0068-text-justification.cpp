class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {
            vector<string> curr;
            int need = maxWidth;
            bool lastRow = false;
            int j;
            for (j = i; j < words.size(); j++) {
                if (words[j].size() <= need && need > 0) {
                    curr.push_back(words[j]);
                    need = need - words[j].size() - 1;
                } else {
                    need++;
                    // cout<<need<<endl;
                    i = j - 1;
                    break;
                }
                cout<<need<<" "<<words[j]<<endl;
            }
            if (j == words.size()) {
                lastRow = true;
                i = words.size();
            }
            if (curr.size() == 1) {
                lastRow = true;
            }
            if (!lastRow) {
                int all = 0, extra = 0;
                if (need > 0) {
                    all = need / (curr.size() -1) ;
                    extra = need %  (curr.size() -1);
                }
                // cout<<extra<<"ok"<<endl;

                string temp = "";

                for (int k = 0; k < curr.size() -1; k++) {
                    temp += curr[k] + " ";
                    if (all) {
                        // cout<<all<<" "<<extra<<endl;
                        int add = all;
                        while (add--) {
                            temp += " ";
                        }
                        
                    }
                    if (extra) {
                            temp += " ";
                            extra--;
                        }
                }
                temp += curr[curr.size() - 1];

                ans.push_back(temp);
            } else {
                string temp = "";
                
                for (int k = 0; k < curr.size() - 1; k++) {
                    temp += curr[k] + " ";
                }
                temp += curr[curr.size() - 1];
                while (temp.size() < maxWidth) {
                    temp += " ";
                }
                ans.push_back(temp);
            }

        }
        return ans;
    }
};