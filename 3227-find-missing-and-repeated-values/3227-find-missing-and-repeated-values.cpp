class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, int> mpp;
        int ans1 = 0;
        for(int i =0; i < n; i++){
            for(int j =0; j < n; j++){
                mpp[grid[i][j]]++;
                if(mpp[grid[i][j]] == 2){
                    ans1 = grid[i][j];
                }
            }
        }
        int j = 1, ans2 = 0;
        while(j <= n*n){
            if(mpp.find(j) == mpp.end()){
                ans2 = j;
                break;
            }
            j++;
        }
        return {ans1, ans2};
    }
};