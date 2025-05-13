class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> qu;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!qu.empty() && qu.front() <= i - k) {
                qu.pop_front();
            }
            while (!qu.empty() && nums[qu.back()] <= nums[i]){
                qu.pop_back();
            }
            qu.push_back(i);
            if(i  >= k - 1) ans.push_back(nums[qu.front()]);
        }
        return ans;
    }
};