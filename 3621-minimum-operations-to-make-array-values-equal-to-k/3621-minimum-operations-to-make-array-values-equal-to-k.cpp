class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map< int, int > mpp;
        for(auto i : nums){
            mpp[i]++;
        }
        int ans = 0;

        for(auto i :mpp){
            if(i.first < k) return -1;
            else if(i.first > k) ans++;
        }
        return ans;
    }
};