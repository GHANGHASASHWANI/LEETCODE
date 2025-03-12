class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map< int , int> mpp;
        vector< int > ans;
        for(auto i : nums){
            mpp[i]++;
        }
        int freq = nums.size() / 3;
        for(auto i : mpp){
            if(i.second > freq) ans.push_back(i.first);
        }
        return ans;
    }
};