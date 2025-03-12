class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map< int , int> mpp;
        // vector< int > ans;
        // for(auto i : nums){
        //     mpp[i]++;
        // }
        // int freq = nums.size() / 3;
        // for(auto i : mpp){
        //     if(i.second > freq) ans.push_back(i.first);
        // }
        // return ans;

        sort(nums.begin(), nums.end());
        int curr = 1;
        vector< int > ans;
        int freq = nums.size() / 3;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                curr++;
            }else{
                if(curr > freq){
                    ans.push_back(nums[i-1]);
                }
                curr = 1;
            }
        }
         if(curr > freq){
            ans.push_back(nums[nums.size() - 1]);
        }
        return ans;
    }
};