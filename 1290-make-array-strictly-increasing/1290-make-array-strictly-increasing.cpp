class Solution {
private:
    map< pair<int, int>, int> dp;
    int fn(vector<int> &arr1, vector<int> &arr2, int curr, int prev){
        if(curr >= arr1.size()) return 0;

        if(dp.count({curr, prev})) return dp[{curr, prev}];

        int ans1 = 2001, ans2 = 2001;

        if(arr1[curr] > prev){
            ans1 = fn(arr1, arr2, curr + 1, arr1[curr]);
        }
        int idx = upper_bound(arr2.begin(), arr2.end(), prev) -  arr2.begin();
        if(idx < arr2.size()){
            ans2 = 1 + fn(arr1, arr2, curr + 1, arr2[idx]);
        }
        return dp[{curr, prev}]  = min(ans1, ans2);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int result = fn(arr1, arr2,0, -1);
        if(result == 2001) return -1;
        return result;
    }
};