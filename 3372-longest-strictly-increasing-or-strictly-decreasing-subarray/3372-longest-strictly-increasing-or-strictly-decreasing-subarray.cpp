class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlen = 0, minlen = 0;
        int templen = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                templen++;
                maxlen = max(maxlen, templen);
            }else{
                templen = 1;
            }
        }
        maxlen = max(maxlen, templen);

        templen = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                templen++;
                minlen = max(minlen, templen);
            }else{
                templen = 1;
            }
        }
        minlen = max(minlen, templen);
        return max(maxlen, minlen);
    }
};