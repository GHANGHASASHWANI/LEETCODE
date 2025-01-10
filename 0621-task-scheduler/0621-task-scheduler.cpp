class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mpp;
        n++;
        int ans = 0;
        for (auto i : tasks) {
            mpp[i]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto i : mpp) {
            pq.push({i.second, i.first});
        }
        string res = "";
        while (!pq.empty()) {
            int temp = n;
            map<char, int> mp;
            while (temp > 0) {
                if (!pq.empty()) {
                    char ch = pq.top().second;
                    int freq = pq.top().first;
                    res += ch;
                    pq.pop();
                    mp[ch] = freq - 1;
                    ans++;
                } else {
                    res += 'i';
                    ans++;
                }
                temp--;
            }
            for (auto i : mp) {
                if (i.second > 0)
                    pq.push({i.second, i.first});
            }
        }
        cout<<res<<" "<<endl;
        while (res[res.size() - 1] == 'i')
            res.pop_back();
        cout<<res<<" ";
        return res.size();
    }
};