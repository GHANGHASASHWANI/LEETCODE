class Solution {
public:

    int mod = 1e9 + 7;
long long modPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL*result * base) % mod;
        base = (1LL*base * base) % mod;
        exp /= 2;
    }
    return result;
}
    int countGoodNumbers(long long n) {
        long long even;
        if(n % 2 == 0){
            even = n / 2;
        }else{
            even = (n) / 2 + 1 ;
        }
        long long odd = n - even;
        long long ans = (((long long)modPow(5, even) % mod) * ((long long)modPow(4, odd) % mod)) % mod;
        return ans;
    }
};