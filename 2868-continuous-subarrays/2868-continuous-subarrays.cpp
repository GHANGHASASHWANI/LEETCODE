class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> frequency;
        int left = 0;
        int right = 0;
        long long count = 0;

        while(right < nums.size()){
            frequency[nums[right]]++;
            while(frequency.rbegin()->first - frequency.begin()->first > 2){
                frequency[nums[left]]--;
                if(frequency[nums[left]] == 0){
                    frequency.erase(nums[left]);
                }
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};