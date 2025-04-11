class Solution {
private:
    // vector<vector< int >> dp;
    // int fn(int i, int j, vector<int> &nums1, vector<int> &nums2){
    //     if(i >= nums1.size() || j >= nums2.size()) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int ans1 = 0;
    //     if(nums1[i] == nums2[j]){
    //         ans1 = 1 + fn(i+1, j+1, nums1, nums2);
    //     }else{
    //         ans1 = max(fn(i+1, j, nums1, nums2), fn(i, j+1, nums1, nums2));
    //     }
    //     return dp[i][j] = ans1;
    // }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // dp.clear();
        // dp.resize(nums1.size()+1, vector<int> (nums2.size()+1, -1));
        // return fn(0, 0, nums1, nums2);

        int n = nums1.size(), m = nums2.size();
        vector<vector< int >> dp(n+1, vector<int> (m+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                 int ans1 = 0;
                if(nums1[i] == nums2[j]){
                    ans1 = 1 + dp[i+1][j+1];
                }else{
                    ans1 = max(dp[i+1][j], dp[i][j+1]);
                }
                 dp[i][j] = ans1;
            }
        }
        return dp[0][0];
    }
};