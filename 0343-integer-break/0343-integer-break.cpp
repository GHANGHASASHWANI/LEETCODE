class Solution {
public:
    int maximumProduct(int n, int product, vector<int>& dp) {
        if (n == 0)
            return product;
        if (n < 0)
            return INT_MIN;
        if (dp[n] != -1)
            return dp[n];

        int maxProduct = 1;
        for (int i = 1; i < n; i++) {
            maxProduct =
                max(maxProduct,
                    max(i * (n - i), i * maximumProduct(n - i, product, dp)));
        }
        return dp[n] = maxProduct;
    }
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n + 1, -1);

        return maximumProduct(n, 1, dp);
    }
};