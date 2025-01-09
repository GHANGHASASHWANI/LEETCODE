class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> answer(nums.size(), -1);
        stack< pair< int, int> > st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && st.top().first < nums[i]) {
                int idx = st.top().second;
                st.pop();
                answer[idx] = nums[i];
            }
            st.push({nums[i],i});
        }
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && st.top().first < nums[i]) {
                int idx = st.top().second;
                st.pop();
                answer[idx] = nums[i];
            }
        }
        
        return answer;
    }
};