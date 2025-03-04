class Solution {
public:
    bool check(int curr, int k){
        if(curr < 0){
            return false;
        }
        if(curr == 0){
            return true;
        }
        if(k < 0) return false;
        int newCurr = curr - pow(3, k);
        bool ans1 = check(newCurr, k-1);
        bool ans2 = check(curr, k-1);
        return ans1 || ans2;
    }
    bool checkPowersOfThree(int n) {
        int k = log2(n) / log2(3);
        return check(n, k);
    }
};