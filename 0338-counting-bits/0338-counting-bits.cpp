class Solution {
public:
    vector<int> countBits(int n) {
        if( n == 0 ) return {0};
        else if (n == 1) return {0, 1};
        vector<int> counting(n + 1);
        // Base Case for 0 and 1
        counting[0] = 0;
        counting[1] = 1;

        for (int index = 2; index <= n; index++) {
            if (index % 2 == 0) {
                // if num is even the no. of 1's = 1's of num / 2
                counting[index] = counting[index / 2];
            } else {
                // if num is even the no. of 1's = 1's of num / 2 + 1
                counting[index] = counting[index / 2] + 1;
            }
        }
        return counting;
    }
};