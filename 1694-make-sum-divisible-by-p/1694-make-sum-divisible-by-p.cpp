class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        if (sum % p == 0) return 0;

        vector<long long> res(n);
        for (int i = 0; i < n; i++) res[i] = 1ll * nums[i];

        for (int j = 1; j < n; j++) {
            bool check = false;
            for (int i = 0; i < n && !check; i++) {
                if ((sum - res[i]) % p == 0) return j;
                if (i + j < n) res[i] += nums[i + j];
                else check = true;
            }
        }
        return -1;
    }
};