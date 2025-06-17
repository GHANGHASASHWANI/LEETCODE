class Solution {
public:
    const int mod = 1e9 + 7;

    // Function to calculate modular inverse using Fermat’s Little Theorem
    long long modInverse(long long a) {
        long long res = 1;
        int p = mod - 2;
        while (p) {
            if (p & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            p >>= 1;
        }
        return res;
    }

    long long fact(int n, int k) {
        long long ans = 1;
        for (int i = n; i > (n - k); i--) {
            ans = (ans * i) % mod;
        }

        long long ans2 = 1;
        for (int i = k; i >= 1; i--) {
            ans2 = (ans2 * i) % mod;
        }

        // Correct modular division using modInverse
        long long res = (ans * modInverse(ans2)) % mod;
        return res;
    }

    int countGoodArrays(int n, int m, int k) {
        long long ans = 1;

        ans *= m; // fix the first number

        long long comb1 = fact(n - 1, k); // n-1 choose k

        long long remain = 1;
        int need = n - 1 - k;

        while (need--) {
            remain = (remain * (m - 1)) % mod;
        }

        cout << ans << " " << comb1 << " " << remain << endl;

        ans = ((ans % mod) * (comb1 % mod) % mod * (remain % mod)) % mod;

        return ans;
    }
};
