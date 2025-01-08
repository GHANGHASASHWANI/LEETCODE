class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        map<char, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        for (auto i : mp) {
            pq.push({i.second, i.first});
        }
        string res = "";
        while (pq.size() > 1) {
            int freq1 = pq.top().first;
            char ch1 = pq.top().second;
            pq.pop();
            int freq2 = pq.top().first;
            int ch2 = pq.top().second;
            pq.pop();
            res += ch1;
            res += ch2;
            freq1--, freq2--;
            if (freq1 > 0) {
                pq.push({freq1, ch1});
            }
            if (freq2 > 0) {
                pq.push({freq2, ch2});
            }
        }
        if (pq.size() == 1) {
            res += pq.top().second;
        }
        if (res.size() < s.size())
            return "";
        return res;
    }
};