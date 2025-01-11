class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        map< char, int> mpp;
        for(auto i : s){
            mpp[i]++;
        }
        int ans = 0;
        for(auto i : mpp){
            if(i.second % 2 != 0){
                ans++;
            }
        }
        if(ans > k) return false;
        return true;
    }
};