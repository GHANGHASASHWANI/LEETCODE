class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map< int, int> mpp;
        int flag = false;
        for(auto i : nums){
            if(mpp[i] != 0) flag = true;
            mpp[i]++;
        }
        if(!flag) return 0;

        int i  = 0;
        int ans = 0;
        while(i < nums.size()){
            int need = i + 3;
            while(i < need && i < nums.size()){
                mpp[nums[i]]--;
                i++;
            }
            int flag = false;
            for(auto i : mpp){
                if(i.second > 1) flag = true;
            }
            ans++;
            if(!flag) return ans;
            i = need;
        }

        return ans;
    }
};