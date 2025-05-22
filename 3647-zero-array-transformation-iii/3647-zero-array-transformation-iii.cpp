class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> available;
        priority_queue<int, vector<int>, greater<int>> used;
        int n = nums.size();
        sort(queries.begin(), queries.end());

        int pos = 0;

        for (int i =0; i < n; i++) {
            while (pos < queries.size() && queries[pos][0] == i) {
                available.push(queries[pos][1]);
                pos++;
            }
            nums[i] -= used.size();

            while (nums[i] > 0 && !available.empty() && available.top() >= i) {
                used.push(available.top());
                available.pop();
                nums[i]--;
            }
            if (nums[i] > 0) return -1;
            
            while (!used.empty() && used.top() <= i) {
                used.pop();
            }
        }

        return available.size();
    }
};