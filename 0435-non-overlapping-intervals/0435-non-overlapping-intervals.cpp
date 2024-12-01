bool cmp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (end1 > intervals[i][0]) {
                start1 = min(start1, intervals[i][0]);
                end1 = min(end1, intervals[i][1]);
                ans++;
            } else {
                start1 = intervals[i][0];
                end1 = intervals[i][1];
            }
        }
        return ans;
    }
};