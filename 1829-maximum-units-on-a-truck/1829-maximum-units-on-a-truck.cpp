typedef pair<int, int> pp;
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pp> pq;

        for (int i = 0; i < boxTypes.size(); i++) {
            pq.push({boxTypes[i][1], boxTypes[i][0]});
        }
        int total = 0;
        while (truckSize > 0 && !pq.empty()) {
            int qnt = pq.top().second;
            int profit = pq.top().first;
            pq.pop();
            // cout<<profit<<" ";
            if (truckSize >= qnt) {
                truckSize -= qnt;
                total += qnt * profit;

            } else {
                total += truckSize * profit;
                truckSize = 0;
            }
        }
        return total;
    }
};