class Solution {
public:
    vector< int > ns(vector< int > & arr){
        int n = arr.size();
        vector< int> nsee(n);
        stack<int> st;

        for(int i =n-1; i >=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nsee[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nsee;
    }

    vector< int > nge(vector< int > &arr){
        int n = arr.size();
        vector< int > ngee(n);
        stack< int > st;
        for(int i =0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ngee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ngee;
    }

    int sumSubarrayMins(vector<int>& arr) {
       vector< int > nse = ns(arr);
       vector< int > psee = nge(arr);
       int total = 0, mod = (int)(1e9+7);
       for(int i =0; i < arr.size(); i++){
        int left = i - psee[i];
        int right = nse[i] - i;
        total = (total + (right * left * 1LL*arr[i])%mod)%mod;
       }
       return total;
    }
};