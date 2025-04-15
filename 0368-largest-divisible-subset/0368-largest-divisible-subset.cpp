class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();

        vector< int > dp(len, 1);
        vector< int > position(len, 0);
        int lastIdx = 0;
        int res = 1;
        for(int i = 0; i < len; i++){
            position[i] = i;
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        position[i] = j;
                    }
                }
            }
            if(res < dp[i]){
                res = dp[i];
                lastIdx = i;
            }
        }

        vector< int > ans;

        while(position[lastIdx] != lastIdx){
            ans.push_back(arr[lastIdx]);
            lastIdx = position[lastIdx];
        }
        ans.push_back(arr[lastIdx]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};