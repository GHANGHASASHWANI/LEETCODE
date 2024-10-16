class Solution {
public:

    int findSubarray(int index , vector< int > &nums, vector<vector< int >> &compute, int diff, int total){
        if(index == nums.size()) return total;
        int count = 0;

        if(compute[index][diff + 1001] != -1) return compute[index][diff + 1001];

        for(int start = index; start < nums.size() - 1; start++){
            int currDiff = nums[start + 1] - nums[start];
            if(diff == currDiff) count++;
            else{
                return compute[index][diff + 1001] = findSubarray(start + 1, nums, compute, currDiff, total);
            }
            total += count;
        }
        return compute[index][diff + 1001] = total;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if(size < 3) return 0;
        vector<vector< int >> compute(size + 1, vector<int> (2005, -1));
        return findSubarray(1, nums, compute, nums[1] - nums[0], 0);

    }
};