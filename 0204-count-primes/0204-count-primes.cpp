class Solution {
private:
    void primesFactor(vector<int> &primes) {
        primes[0] = primes[1] = 1;

        for (int i = 2; i < primes.size(); i++) {
            for (int j = 2; i*j < primes.size(); j++) {
                    primes[i*j] = 1;
            }
        }
    }
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) return 0;

        vector<int> primes(n, 0);
        int count = 0;

        primesFactor(primes);

        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] == 0) {
                count++;
            }
        }
        return count;
    }
};