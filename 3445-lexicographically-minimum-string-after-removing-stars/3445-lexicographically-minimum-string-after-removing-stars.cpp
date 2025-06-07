struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first ) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
class Solution {
public:
    
    typedef pair<int, int> pp;
    string clearStars(string s) {
        priority_queue<pp, vector<pp>, cmp> pq;

        for (int i= 0; i < s.size(); i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                auto top = pq.top();
                pq.pop();
                s[top.second] = '*';
            }
        }

        string res = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                res += s[i];
            }
        }
        return res;
    }
};