class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> mp;

        for (auto i : s) {
            mp[i]++;
        }
        priority_queue<pair<char, int>> pq;

        for (auto p : mp) {
            pq.push(p);
        }
        string result = "";
        while (!pq.empty()) {
            auto largest = pq.top();
            pq.pop();
            int length = min(repeatLimit, largest.second);
            for (int i = 0; i < length; i++) {
                result += largest.first;
            }
            if (largest.second - length > 0) {
                pair<char, int> largest2;
                if (!pq.empty()) {
                    largest2 = pq.top();
                    pq.pop();
                    result += largest2.first;
                } else {
                    return result;
                }
                if (largest2.second - 1 > 0)
                    pq.push({largest2.first, largest2.second - 1});
                pq.push({largest.first, largest.second - length});
            }
        }
        return result;
    }
};