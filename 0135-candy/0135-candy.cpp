class Solution {
public:
    typedef pair<int, int> pp;
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (int i = 0; i < ratings.size(); i++) {
            pq.push({ratings[i], i});
        }
        vector<int> ans(n, 1);
        while (not pq.empty()) {
            int currIdx = pq.top().second;
            int currRating = pq.top().first;
            pq.pop();

            if (currIdx > 0 && ratings[currIdx] < ratings[currIdx - 1] ) {
                ans[currIdx - 1] = max(ans[currIdx - 1], ans[currIdx] + 1);
            }
            if (currIdx  < n - 1 && ratings[currIdx] < ratings[currIdx + 1]) {
                ans[currIdx + 1] = max(ans[currIdx + 1], ans[currIdx] + 1);
            }
            
        }
        int sum = 0;
        for (auto i : ans) {
            sum += i;
        }
        return sum;
    }
};