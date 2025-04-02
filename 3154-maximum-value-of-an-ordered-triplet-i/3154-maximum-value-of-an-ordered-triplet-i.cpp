class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n, 0);
        prefMax[0] = 0;

        for(int i =1; i < n; i++){
            prefMax[i] = max(prefMax[i-1], nums[i-1]);
        }

        vector< int> sufMax(n, 0);
        sufMax[n-1] = 0;

        for(int i =n-2; i >=0; i--){
            sufMax[i] = max(sufMax[i+1], nums[i+1]);
        }

        long long ans = 0;

        for(int i =0; i <n; i++){
            // long long sum =  (prefMax[i] - nums[i])*sufMax[i];
            ans = max(ans,(long long)(prefMax[i] - nums[i])*sufMax[i]);
        }
        return ans;
    }
};