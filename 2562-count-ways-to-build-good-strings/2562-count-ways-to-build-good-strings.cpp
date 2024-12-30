class Solution {
public:
    vector<int> dp;
    int m = 1e9 + 7;
    int count(int length, int high, int low, int zero, int one) {
        if (dp[length] != -1)
            return dp[length];
        int answer = 0;
        if (length > high) {
            return 0;
        }
        if (length >= low && length <= high) {
            answer = 1;
        }
        int addOne = count(length + one, high, low, zero, one) % m;

        int addZero = count(length + zero, high, low, zero, one) % m;
        return dp[length] = (answer + addOne + addZero) % m;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.clear();
        dp.resize(1000001, -1);
        return count(0, high, low, zero, one);
    }
};