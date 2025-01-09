class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector< int > nextElement;
        map< int, int> mpElement;
        stack< int > st;
        for(int i = 0; i < nums2.size(); i++){
            while(!st.empty() && st.top()<nums2[i]){
                int top = st.top();
                st.pop();
                mpElement[top] = nums2[i];
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            if(mpElement.find(nums1[i]) == mpElement.end()){
                nextElement.push_back(-1);
            }else{
                nextElement.push_back(mpElement[nums1[i]]);
            }
        }
        return nextElement;
    }
};