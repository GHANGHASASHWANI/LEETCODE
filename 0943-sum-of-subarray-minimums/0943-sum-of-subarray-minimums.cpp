class Solution {
public:
    vector<int> nse(vector<int> &arr){
        vector<int> ans(arr.size());
        int n = arr.size();
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            else {
                ans[i] = n;
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int> &arr){
        vector<int> ans(arr.size());
        int n = arr.size();
        stack<int> st;

        for (int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] >= arr[i]){
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

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> psee = pse(arr);
        vector<int> nsee = nse(arr);

        int total = 0, mod = 1e9 + 7;

        for (int i =0; i < arr.size(); i++) {
            int leftArr = i - psee[i];
            int rightArr = nsee[i] - i;

            // cout<<leftArr<<" "<<rightArr<<endl;

            total = (total + 1LL * leftArr * rightArr * arr[i]) % mod;
        }
        return total;
    }
};