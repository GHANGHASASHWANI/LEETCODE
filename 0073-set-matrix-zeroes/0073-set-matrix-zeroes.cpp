class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowLen = matrix.size(), colLen = matrix[0].size();
        set<int> rows;
        set<int> cols;

        for (int i= 0; i < rowLen; i++) {
            for (int j =0; j < colLen; j++) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(int i =0; i < rowLen; i++) {
            for (int j = 0; j < colLen; j++) {
                if (rows.count(i) || cols.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};