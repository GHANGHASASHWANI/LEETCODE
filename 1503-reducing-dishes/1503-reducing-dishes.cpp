class Solution {
private:
    vector< vector< int >> dp;
    long long fn(vector<int> & arr, int idx, int curr){
        if(idx >= arr.size()) return 0;
        if(dp[idx][curr] != -1) return dp[idx][curr];

        long long pick = arr[idx]*curr + fn(arr, idx+1, curr+1);
        long long nonPick = fn(arr, idx+1, curr);

        return dp[idx][curr] = max(pick, nonPick);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        dp.clear();
        int n = satisfaction.size();
        dp.resize(n + 5, vector< int > (n+5, -1));
        sort(satisfaction.begin(), satisfaction.end());
        long long ans = fn(satisfaction, 0, 1);

        if(ans < 0) return 0;

        return ans;
    }
};