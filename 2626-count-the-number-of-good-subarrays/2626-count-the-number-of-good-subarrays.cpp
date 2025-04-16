class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map< int, int > mpp;

        int i =0, j = 0;
        int pairs = 0;

        while(j < nums.size()){
            pairs += mpp[nums[j]];
            mpp[nums[j]]++;

            while(pairs >= k){
                ans += (nums.size() - j);
                mpp[nums[i]]--;
                pairs -= mpp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};