class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr);
        sort(temp.begin(), temp.end());

        unordered_map<int, int> values;
        int rank = 1;
        for(int i = 0; i < arr.size(); i++){
            if(values.find(temp[i]) == values.end()){
                values[temp[i]] = rank;
                rank++;
            }
        }

        for(int i = 0; i < arr.size(); i++){
            temp[i] = values[arr[i]];
        }
        return temp;
    }
};