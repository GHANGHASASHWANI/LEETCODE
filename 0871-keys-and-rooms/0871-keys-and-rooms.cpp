class Solution {
public:
    void visitRooms(vector<vector<int>>& rooms, int currentRoom,
                    vector<int>& visited) {
        visited[currentRoom] = 1;
        for (auto neighbour : rooms[currentRoom]) {
            if (not visited[neighbour]) {
                visitRooms(rooms, neighbour, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int totalRooms = rooms.size();
        vector<int> visited(totalRooms, 0);
        visitRooms(rooms, 0, visited);

        for (int i = 0; i < visited.size(); i++) {
            if (not visited[i])
                return false;
        }
        return true;
    }
};