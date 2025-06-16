class Solution {
public:
    typedef pair<int, char> pp;
    string frequencySort(string s) {
        priority_queue<pp> pq;
        map<char, int> mpp;

        for (auto it : s) {
            mpp[it]++;
        }
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }
        string res = "";
        while (not pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int freq = it.first;
            char ch = it.second;
            while (freq--) {
                res += ch;
            }
        }
        return res;
    }
};