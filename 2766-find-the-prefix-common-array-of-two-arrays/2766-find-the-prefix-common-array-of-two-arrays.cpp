class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map< int , int > mpp;
        vector< int > result;
        for(int i =0; i < A.size(); i++){
            mpp[A[i]]++;
            mpp[B[i]]++;
            int ans = 0;
            for(auto i : mpp){
                if(i.second == 2) ans++;
            }
            result.push_back(ans);
        }
        return result;
    }
};