class Solution {
public:
    pair<int, int> check(vector<int> &nums, int mid) {
        int ans = 0;
        int total = 1;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
           if (ans + nums[i] <= mid) {
                ans = ans + nums[i];
           } else {
                maxi = max(maxi, ans);
                total++;
                ans = nums[i];
           }
        }
        
        pair<int, int> res = make_pair(total, maxi);
        return res;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int low = *max_element(nums.begin(), nums.end()), high = sum;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // cout<<mid<<" "<<check(nums, mid)<<endl;
            pair<int, int> res = check(nums, mid);
            cout<<mid<<" "<<res.first<<" "<<res.second<<endl;
            if (res.first == k) {
                ans = min(ans, res.second);
                high = mid - 1;
            } 
            else if (res.first > k) {
                low = mid + 1;
            }
             else {
                high = mid - 1;
            }
        }
        return low;
    }
};