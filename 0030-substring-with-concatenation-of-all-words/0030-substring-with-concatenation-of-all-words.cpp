class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int  size = words[0].size();
        int window = size * words.size();
        map<string, int> mpp;
        vector<int> ans;

        for (auto &it : words) {
            mpp[it]++;
        }
        for (int k = 0; k < size; k++) {

             if (k + window > s.size()) continue;
        map<string, int> check;
        for (int i = k; i < window; i += size) {
            string temp = s.substr(i, size);
            check[temp]++;
        }
        int i = k, j = k +  window;
        if (mpp == check) {
            ans.push_back(i);
        }
        

        while (j < s.size()) {
            string temp = s.substr(i, size);
            check[temp]--;
            if (check[temp] == 0) {
                check.erase(temp);
            }
            string newTemp = s.substr(j, size);
            check[newTemp]++;
            i += size;
            j += size;
            if (mpp == check) {
                ans.push_back(i);
            }
        }

        }
        return ans;
    }
};