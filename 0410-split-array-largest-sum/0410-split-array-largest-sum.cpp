class Solution {
public:
    int check(vector<int> &nums, int mid) {
        int ans = 0;
        int total = 1;
        for (int i = 0; i < nums.size(); i++) {
           if (ans + nums[i] <= mid) {
                ans = ans + nums[i];
           } else {
                total++;
                ans = nums[i];
           }
        }
        
        
        return total;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int low = *max_element(nums.begin(), nums.end()), high = sum;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = check(nums, mid);
            if (res == k) {
                high = mid - 1;
            } 
            else if (res > k) {
                low = mid + 1;
            }
             else {
                high = mid - 1;
            }
        }
        return low;
    }
};