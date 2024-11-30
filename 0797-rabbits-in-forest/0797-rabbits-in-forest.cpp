class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int total = 0;
        for (int i = 0; i < answers.size(); i++) {
            if (!mp[answers[i] + 1]) {
                total += answers[i] + 1;
                if (answers[i] == 0)
                    continue;
                mp[answers[i] + 1]++;
            } else {
                mp[answers[i] + 1]++;
                int key = answers[i] + 1;
                int val = mp[answers[i] + 1];
                if (key == val) {
                    mp.erase(key);
                }
            }
        }
        return total;
    }
};