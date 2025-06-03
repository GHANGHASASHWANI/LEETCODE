class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> hasBox(n, false);
        vector<int> visited(n, false);

        queue<int> qu;
        int total = 0;

        for (auto it: initialBoxes) {
            hasBox[it] = true;

            if (status[it]) {
                qu.push(it);
                visited[it] = true;
            }
        }

        while (not qu.empty()) {
            int top = qu.front();
            qu.pop();
            total += candies[top];

            for (auto &it : keys[top]) {
                if (not status[it]) {
                    status[it] = true;
                    if (hasBox[it] and not visited[it]) {
                        visited[it] = true;
                        qu.push(it);
                    }
                }
            }

            for (auto &it : containedBoxes[top]) {
                hasBox[it] = true;
                if (hasBox[it]) {
                    if (status[it] and not visited[it]) {
                        visited[it] = true;
                        qu.push(it);
                    }
                }
            }
        }

        return total;
    }
};