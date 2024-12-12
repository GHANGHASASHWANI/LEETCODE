class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

       vector<bool> ans;
        vector<int> banned(nums.size());
        banned[0]=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2){
                banned[i]=banned[i-1]+1;
            }
            else{
                banned[i]=banned[i-1];
            }
        }
        for(int i=0;i<queries.size();i++){
            if(banned[queries[i][0]]==banned[queries[i][1]]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};