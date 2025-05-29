class Solution {
private:
    int findPeak(vector<int>& arr) {
        int maxi = -1, idx = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
                idx = i;
            }
        }
        return idx;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();

        int low = 0, high = row - 1;
        while (low <= high) {
            int i = (low + high) / 2;
            int maxi = findPeak(mat[i]);
            int current = mat[i][maxi];
            int up = (i > 0) ? mat[i - 1][maxi] : -1;
            int down = (i < row - 1) ? mat[i + 1][maxi] : -1;

            if (current >= up && current >= down) {
                return {i, maxi};
            } else if (down > current) {
                low = i + 1;
            } else {
                high = i - 1;
            }
        }

        return {-1, -1};
    }
};