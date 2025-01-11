class Solution {
public:
    vector< int> NGE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, n);
        for(int i = n -1; i >=0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector< int> NSE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, n);
        for(int i = n -1; i >=0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector< int > &arr){
        int n = arr.size();
        stack< int > st;
        vector< int > ans(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector< int > PGE(vector< int > &arr){
        int n = arr.size();
        stack< int > st;
        vector< int > ans(n, -1);
        for(int i =0; i < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& arr) {
        vector< int > NG = NGE(arr);
        vector< int > NS = NSE(arr);
        vector< int > PS = PSE(arr);
        vector< int > PG = PGE(arr);

        long long minSum = 0, maxSum = 0;

        for(int i =0; i < arr.size(); i++){
            long long left = i - PS[i];
            long long right = NS[i] - i;
            minSum = (minSum + 1LL * left * right * arr[i]); 
        }

        for(int i =0; i < arr.size(); i++){
            long long left = i - PG[i];
            long long right = NG[i] - i;
            maxSum = (maxSum + 1LL* left* right * arr[i]);
        }

        return maxSum - minSum;
    }
};