class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map< int, int > mpp;
        for(auto i : nums){
            mpp[i]++;
        }

        for(auto i : mpp){
            if(i.second > 2) return false;
        }
        return true;
    }
};