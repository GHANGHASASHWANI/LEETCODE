class Solution {
public:
    int hammingDistance(int x, int y) {
        int need = x ^ y;
        int ans = 0;

        while (need > 0) {
            need = need & (need - 1);
            ans++;
        }
        return ans;
    }
};