class Solution {
public:
    int minBitFlips(int start, int goal) {
        int need = start ^ goal;

        int ans = 0;

        while (need > 0) {
            need = need & (need - 1);
            ans++;
        }
        return ans;
    }
};