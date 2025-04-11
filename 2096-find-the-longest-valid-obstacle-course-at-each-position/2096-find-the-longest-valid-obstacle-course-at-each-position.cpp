class Solution {
private:
    vector<vector< int >> dp;
    int fn(int idx, int prev, vector<int> &arr){
        if(idx < 0) return 0;

        if(dp[idx][prev] != -1) return dp[idx][prev];

        int pick = 0;
        if(arr[prev] >= arr[idx]){
            pick = 1 + fn(idx -1, idx, arr);
        }
        int nonPick = fn(idx-1, prev, arr);

        return dp[idx][prev] = max(pick, nonPick);
    }
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // int n = obstacles.size();
        // vector<int> arr(n);
        // dp.clear();
        // dp.resize(n, vector< int > (n, -1));
        // for(int i =0; i < obstacles.size(); i++){
        //     arr[i] = fn(i, i, obstacles);
        // }
        // return arr;

        int n = obstacles.size();
        vector< int > dp;
        vector< int > result(n);

        for(int i = 0; i <n; i++){
            int idx = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();

            if(idx == dp.size()){
                dp.push_back(obstacles[i]);
            }else{
                dp[idx] = obstacles[i];

            }
            result[i] = idx+1;
        }
        return result;
    }
};