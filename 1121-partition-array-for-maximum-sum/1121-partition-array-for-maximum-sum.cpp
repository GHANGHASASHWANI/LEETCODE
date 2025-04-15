class Solution {
private:
    int maxSum(int idx, const vector< int > &arr, const int k, vector< int > &dp){
        if(idx == arr.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int maxi = INT_MIN;
        int maxEle = arr[idx];

        for(int i = idx; i < idx + k && i < arr.size(); i++){
            maxEle = max(arr[i], maxEle);
            int sum = (i - idx + 1)* maxEle + maxSum(i + 1, arr, k, dp);
            maxi = max(sum, maxi);
        }

        return dp[idx] = maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // int n = arr.size();
        // vector< int > dp(n, -1);
        // return maxSum(0, arr, k, dp);

        int n = arr.size();
        vector< int > dp(n+1, 0);

        for(int idx = n - 1; idx >= 0; idx--){
            int maxi = INT_MIN;
            int maxEle = arr[idx];

            for(int i = idx; i < idx + k && i < arr.size(); i++){
                maxEle = max(arr[i], maxEle);
                int sum = (i - idx + 1)* maxEle +dp[i + 1];
                maxi = max(sum, maxi);
            }

            dp[idx] = maxi;
        }

        return dp[0];
    }
};