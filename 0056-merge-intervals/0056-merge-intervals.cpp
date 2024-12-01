bool cmp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(), cmp);

        vector<vector<int>> ans;

        ans.push_back(inter[0]);

        for (int i = 1; i < inter.size(); i++) {
            int start1 = ans[ans.size() - 1][0];
            int end1 = ans[ans.size() - 1][1];
            int start2 = inter[i][0];
            int end2 = inter[i][1];

            if (end1 >= start2) {
                ans[ans.size() - 1][0] = min(start1, start2);
                ans[ans.size() - 1][1] = max(end1, end2);
            } else {
                ans.push_back(inter[i]);
            }
        }
        return ans;
    }
};