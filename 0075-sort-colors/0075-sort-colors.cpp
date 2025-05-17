#pragma GCC optimize("O3", "unroll-loops")
int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;

        while(mid<=high){
            if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }else if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }else{
                mid++;
            }
        }
    }
};