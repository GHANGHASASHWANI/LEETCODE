class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        queue<int> keys;
        keys.push(0);
        visited[0] = true;
        
        while (not keys.empty()) {
            int currRoom = keys.front();
            keys.pop();

            for (auto key : rooms[currRoom]) {
                if (not visited[key]) {
                    keys.push(key);
                    visited[key] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (not visited[i]) return false;
        }
        return true;
    }
};