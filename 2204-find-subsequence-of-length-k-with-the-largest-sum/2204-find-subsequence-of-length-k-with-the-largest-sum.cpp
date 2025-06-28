class Solution {
private:
    bool findNum(vector<int> &arr, int k) {
        for (int  i = 0; i < arr.size(); i++) {
            if (arr[i] == k) {
                arr[i] = 1e6;
                return true;
            }
        }
        return false;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;

        sort(temp.rbegin(), temp.rend());

        temp.resize(k);
        

        vector<int> ans;

        for (int i = 0; i < nums.size() && k; i++) {
            if (findNum(temp, nums[i])) {
                ans.push_back(nums[i]);
                k--;
            }
        }
        
        return ans;
    }
};