class Solution {
public:
    int subarraySum(vector<int>& nums, int p) {
        int size = nums.size();
        vector< int > prefixSum(size, 0);
        prefixSum[0] = nums[0];
        // Calculating the prefix sum of th array nums
        for(int index = 1; index < size; index++){
            prefixSum[index] = nums[index] + prefixSum[index -1];
        }

        // checking the subarray and storing answer in count
        int count = 0;
        unordered_map< int, int> values;
        for(int index = 0; index < size; index++){
            if(prefixSum[index] == p) count++;
            int key = prefixSum[index] - p;
            if(values.find(key) != values.end()){
                count = count + values[key];
            }
            values[prefixSum[index]]++;
        }
    return count;
    }
};
