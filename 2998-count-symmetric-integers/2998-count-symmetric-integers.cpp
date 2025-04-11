class Solution {
private:
#pragma GCC optimize("O3", "unroll-loops")
int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
    int solve(int n){
        int len = log10(n) + 1;
        if(len % 2 != 0) return 0;
        int first = len/2;
        int sum = 0;
        while(first){
            sum += (n % 10);
            n/=10;
            first--;
        }
        int sum2 = 0;
        while(n){
            sum2+= (n % 10);
            n/=10;
        }
        return sum == sum2;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low ; i <= high; i++){
            if(solve(i)) ans++;
        }
        return ans;
    }
};
