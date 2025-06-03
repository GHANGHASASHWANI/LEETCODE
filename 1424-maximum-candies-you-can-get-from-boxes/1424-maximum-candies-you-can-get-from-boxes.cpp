class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int total = 0;
        vector<bool> visited(status.size(), false);
        vector<bool> hasBox(status.size(), false);
        queue<int> qu;

        for (auto i : initialBoxes){ 
            hasBox[i] = true;
            if (status[i]) {
                visited[i] = true;
                qu.push(i);
            }
        }

        while (!qu.empty()) {
            int top = qu.front();
            qu.pop();

            total += candies[top];

            for (auto it : keys[top]) {
                if (!status[it]) {
                    status[it] = 1;
                    if (hasBox[it] && !visited[it]) {
                        visited[it] = true;
                        qu.push(it);
                    }
                }
            }

            for (auto it : containedBoxes[top]) {
                hasBox[it] = true;
                if (status[it] && !visited[it]) {
                    visited[it] = true;
                    qu.push(it);
                }
            }
        }

        return total;
    }
};
