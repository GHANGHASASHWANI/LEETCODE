class Solution {
    private:
    vector<int> prevSmaller(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for (int i =0; i < n; i++){
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            else {
                ans[i] = -1;
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int> &arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()){
                ans[i] = st.top();
            }
            else {
                ans[i] = n;
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) return heights[0];
        vector<int> nSmall = nextSmaller(heights);
        vector<int> pSmall = prevSmaller(heights);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int rightLen = nSmall[i] - i;
            int leftLen = i - pSmall[i];
            int length = rightLen + leftLen - 1;

            maxArea = max(maxArea, length * heights[i]);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int> (m, 0));

        for (int i = 0; i < m; i++){
            prefix[0][i] = matrix[0][i] - '0';
           
            for (int j = 1; j < n; j++) {
                if (matrix[j][i] != '0') {
                    prefix[j][i] = prefix[j - 1][i] + 1;
                }
                else {
                    prefix[j][i] = 0;
                }
            }
        }


        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, largestRectangleArea(prefix[i]));
        }

        return maxArea;
    }
};