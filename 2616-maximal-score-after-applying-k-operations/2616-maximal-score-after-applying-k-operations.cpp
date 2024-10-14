class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<double> getTopMaximum;

        for (int index = 0; index < nums.size(); index++) {
            getTopMaximum.push(nums[index]);
        }
        long long ans = 0;

        while (k--) {
            double maximum = getTopMaximum.top();
            cout << maximum << " ";
            getTopMaximum.pop();
            ans += (int)maximum;
            double insert = ceil((maximum) / 3);
            getTopMaximum.push(insert);
        }
        return ans;
    }
};