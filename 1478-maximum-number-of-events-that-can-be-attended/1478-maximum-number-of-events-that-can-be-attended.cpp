class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int maxDay = events[0][0];
        for (int  i= 0; i < events.size(); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ans =0, lastIdx = 0;
        for (int i= 0, j = 0; i <= maxDay; i++) {
            for (; j < events.size(); j++) {
                if (events[j][0] <= i) {
                    minHeap.push(events[j][1]);
                } else {
                    break;
                }
            }
            while (not minHeap.empty() && minHeap.top() < i) {
                minHeap.pop();
            }
            if (minHeap.size() != 0) {
                minHeap.pop();
                ans++;
            }
        }
        return ans;
    }
};