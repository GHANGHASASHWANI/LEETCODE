class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr(nums.size());
        stack<int> st;
        int n = nums.size();

        for (int i = 2*n - 1; i >= 0 ; i--){
            int curr = i % n;
            while (!st.empty() && st.top() <= nums[curr]){
                st.pop();
            }

            if ((i) / n == 0){
                if (!st.empty()) {
                    arr[i] = st.top();
                }
                else {
                    arr[i] = -1;
                }
            }
            st.push(nums[curr]);
        }
        return arr;
    }
};