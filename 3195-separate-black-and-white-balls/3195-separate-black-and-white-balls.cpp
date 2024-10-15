class Solution {
public:
    long long minimumSteps(string s) {
        long long totalSwap = 0;
        int zeros = 0;
        for(int index = s.size() -1; index >= 0; index--){
            if(s[index] == '0') zeros++;
            else{
                totalSwap += zeros;
                // zeros = 0;
            }
        }
    return totalSwap;
    }
};