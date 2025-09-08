class Solution {
private:
    bool hasZero (int num) {
        int zeroCount =  0;
        while (num != 0) {
            int rem = num % 10;
            if (rem == 0) zeroCount++;
            num = num / 10;
        }
        return zeroCount == 0;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        int currNum = n;
        for (int i = 1; i <= n / 2; i++) {
            if (hasZero(i) && hasZero(n - i)) {
                return {i, n - i};
            }
        }
        return {0, 0};
    }
};