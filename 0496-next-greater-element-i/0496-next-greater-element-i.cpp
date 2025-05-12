class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nge;
        stack<int> st;

        for(int i = nums2.size() - 1; i >= 0; i--){
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) nge[nums2[i]] = -1;
            else nge[nums2[i]] = st.top();

            st.push(nums2[i]);
        }
        vector<int> answer(nums1.size());

        for (int i = 0; i < nums1.size(); i++){
            if(nge.find(nums1[i]) == nge.end()){
                answer[i] = -1;
            }
            else {
                answer[i] = nge[nums1[i]];
            }
        }

        return answer;
    }
};