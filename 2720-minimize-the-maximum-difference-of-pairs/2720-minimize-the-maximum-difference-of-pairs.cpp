class Solution {
private:
    int check(vector<int> &nums, int mid) {
        int ans = 0;
        for (int i = 1; i < nums.size();) {
            if ((nums[i] - nums[i - 1]) <= mid) {
                ans++;
                i += 2;
            } else {
                i++;
            }
        }
        return ans;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 0;

        int low = 0, high = nums[n - 1];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if(check(nums, mid) >= p) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};