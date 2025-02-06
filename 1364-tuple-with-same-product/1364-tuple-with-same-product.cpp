class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map< int, int> mp;
        int ans = 0;
        for(int i =0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }
        for(auto i : mp){
            if(i.second >= 2){
                int pair = (i.second - 1) * i.second/2;
                ans += pair * 8;
            }
        }
        return ans;
    }
};