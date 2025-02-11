class Solution {
public:
    vector< vector< int >> dp;
    int solve(vector< int > &arr, int sum, int target, int i){
        if(sum > target) return 1e8;
        if(sum == target) return 0;
        if(i == arr.size()) return 1e8;
        if(dp[i][sum] != -1) return dp[i][sum];
        int  pick = 1 + solve(arr, sum + arr[i], target,  i);
        int nonpick = solve(arr, sum, target, i + 1);

        return  dp[i][sum] = min(pick, nonpick);
    }

    int numSquares(int n) {
        vector<int> arr;
        int i = 1;
        while(i*i <= n){
            arr.push_back(i*i);
            i++;
        }   
        dp.clear();
        dp.resize(arr.size()+2, vector< int > (n+2, -1));
        return solve(arr, 0, n, 0);
    }
};