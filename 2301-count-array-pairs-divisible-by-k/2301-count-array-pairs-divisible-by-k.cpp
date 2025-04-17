class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        map< int, int> gcd;

        const int len = nums.size();

        long long cntPairs = 0;

        for(int idx = 0; idx < len; idx++){
            int currGCD = __gcd(nums[idx], k);

            for(auto& prevGCD : gcd){
                if((1LL * prevGCD.first * currGCD) % k == 0){
                    cntPairs += prevGCD.second;
                }
            }

            gcd[currGCD]++;
        }

        return cntPairs;
    }
};