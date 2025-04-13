class Solution {
private:
    unordered_map<string, int> dp;
    int fn(int idx, int diff, vector<int> &arr){
        if(idx >= arr.size()) return 0;

        string key = to_string(idx) + "," + to_string(diff);

        if(dp.count(key)) return dp[key];

        int ans = 0;
        for(int i = idx + 1; i < arr.size(); i++){
            int ndiff = arr[i] - arr[idx];
            if(ndiff == diff){
                ans = max(ans, 1 + fn(i, diff, arr));
            }
        }
        return dp[key] = ans;
    }
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        // int result = 0;

        // for(int i = 0; i < arr.size(); i++){
        //     for(int j = i + 1; j < arr.size(); j++){
        //         int diff = arr[j] - arr[i];
        //         if(diff == difference){
        //             result = max(result, 2 + fn(j, diff, arr));
        //         } 
        //     }
        // }
        // return result == 0 ? 1 : result;

        unordered_map< int, int> mp;

        int ans = 0;

        for(auto & i : arr){
            if(mp.find(i - diff) != mp.end()){
                mp[i] = max(mp[i], mp[i-diff]+1);
                ans = max(ans, mp[i]);
            }else{
                mp[i] = 1;
            }
        }
        return ans == 0? 1 : ans;
    }
};