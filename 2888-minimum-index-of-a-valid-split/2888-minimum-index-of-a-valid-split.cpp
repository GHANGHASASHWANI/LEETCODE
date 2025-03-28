class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map< int, int> mpp;

        for(auto i : nums){
            mpp[i]++;
        }
        int maxi = -1, fq = 0;

        for(auto i : mpp){
            if(i.second > fq){
                fq = i.second;
                maxi = i.first;
            }
        }
        int prefix = 0;

        for(int i =0; i < nums.size(); i++){
            if(nums[i] == maxi) prefix++;

            if(prefix > (i+1)/2 && (fq - prefix) >= (nums.size()-i+1)/2){
                return i;
            }
        }
        return -1;
    }
};