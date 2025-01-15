class Solution {
public:
    int ans = 0;
    void fact(int n){
        if(n <= 1) return;
        int temp = n;
        while(temp % 5 == 0){
            temp/=5;
            ans++;
        }
        fact(n -1);
    } 
    int trailingZeroes(int n) {
       fact(n);
       return ans;
    }
};