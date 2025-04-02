class Solution {
public:
    bool recur(vector<int>& nums,vector<int> &memo,int index,int n){
        if(index>=(n-1)){
            return true;
        }
        if(memo[index]!=-1){
            return memo[index];
        }
        for(int i=1;i<=nums[index];i++){
            if(recur(nums,memo,index+i,n)){
                memo[index]=1;
                return true;
            }
        }
        memo[index]=0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n+1,-1);
        return recur(nums,memo,0,n);
    }
};