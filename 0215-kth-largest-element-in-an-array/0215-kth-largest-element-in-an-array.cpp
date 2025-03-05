class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // return nums[n-k];

        // vector<int> ans(nums.size(),0);

        // for(int i=0;i<nums.size();i++){
        //     ans[nums[i]-1]++;
            
        // }
        // int cnt=0;
        // for(int i=ans.size()-1;i>=0;i--){
        //     cnt+=ans[i];
        //     cout<<cnt<<" ";
        //     if(cnt==k || cnt>k){
        //         return i+1;
        //     }
        // }
        // return 0;

        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};