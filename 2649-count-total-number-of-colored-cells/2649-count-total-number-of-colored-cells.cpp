class Solution {
public:
    long long coloredCells(int n) {
        long long k = 0;
        long long ans = 1;
        while(n--){
            ans = ans + k*4;
            k++;
        }
        return ans;
    }
};