class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map< int, int > mpp;
        vector<int> check(nums.size(), 0);

        for(int i = nums.size()-1; i >= 0; i--){
            check[i] = ++mpp[nums[i]];
        }
        int idx = -1;
        for(int i = nums.size()-1; i >=0; i--){
            if(check[i] > 1){
                idx = i;
                break;
            }
        }
        if(idx == -1) return 0;
        int ans = ceil((idx+1)/3.0);
        return ans;
    }
};