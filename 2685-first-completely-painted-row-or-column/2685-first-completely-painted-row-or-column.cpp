class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map< int, set<int> > rows;
        map< int, set<int> > cols;

        map<int, pair<int, int>> values;

        for(int i =0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(values.find(mat[i][j]) == values.end()){
                    values[mat[i][j]].first = i;
                    values[mat[i][j]].second = j;
                }
                rows[i].insert(mat[i][j]);
                cols[j].insert(mat[i][j]);
            }
        }
        for(int i =0; i < arr.size(); i++){
            int row = values[arr[i]].first;
            int col = values[arr[i]].second;
            rows[row].erase(arr[i]);
            cols[col].erase(arr[i]);
            if(rows[row].size() == 0 || cols[col].size() == 0){
                return i;
            }
        }
        return -1;
    }
};