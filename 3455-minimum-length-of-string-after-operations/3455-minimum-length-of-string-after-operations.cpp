class Solution {
public:
    int minimumLength(string s) {
        if (s.size() <= 2)
            return s.size();
        map<char, int> mp;

        for (auto i : s) {
            mp[i]++;
        }
        int ans = 0;
        for (auto i : mp) {
            if (i.second == 2)
                ans += i.second;
            else if (i.second % 2 == 0)
                ans += 2;
            else if (i.second % 2 == 1)
                ans += 1;
        }
        return ans;
    }
};