class Solution {
public:
    bool possible(vector<int> &nums, int mid, int maxOperations){
        int total = 0;
        for(int i =0; i < nums.size(); i++){
            if(nums[i] > mid ) total+= (nums[i] - 1)/mid;
            if(total > maxOperations) return 0;
        }
        return 1;
    }


    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans  = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(nums, mid, maxOperations)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};