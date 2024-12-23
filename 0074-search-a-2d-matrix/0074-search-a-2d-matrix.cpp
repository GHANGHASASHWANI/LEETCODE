class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size() - 1; i++) {
            if (target < matrix[i + 1][0]) {
                bool found = false;
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (target == matrix[i][j])
                        found = true;
                }
                if (found)
                    return true;
                else
                    return false;
            }
        }
        int idx = matrix.size() - 1;
        for (int j = 0; j < matrix[0].size(); j++) {
            if (target == matrix[idx][j])
                return true;
        }
        return false;
    }
};