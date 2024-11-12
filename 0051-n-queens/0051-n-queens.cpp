class Solution {
public:
    bool check(int row, int col, vector<string>&curr, int n){
        for(int i=0; i<row; i++){
            for(int j=0; j<n; j++){
                if(curr[i][j] == 'Q'){
                    if(i == row || j == col || abs(i-row) == abs(j-col)) return false;
                }
            }
        }
        return true;
    }
    vector<vector<string>>ans;
    void placed(int row,vector<string>&curr, int n){
        if(row == n){
            ans.push_back(curr);
            return ;
        }
        for(int j=0; j<n; j++){
            if(check(row,j,curr,n)){
                curr[row][j] = 'Q';
                placed(row+1, curr,n);
                curr[row][j] = '.';
            }
        }
        // return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>curr;
        string str = "";
        for(int i=0; i<n; i++) str += ".";
        for(int i=0; i<n; i++){
            curr.push_back(str);
        }
        placed(0,curr,n);
        return ans;
    }
};