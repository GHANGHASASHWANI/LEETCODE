class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector< bool > arr(right + 1, true);
        arr[0] = arr[1] = false;

        for(int i = 2; i*i <= right; i++){
            if(arr[i]){
                for(int j = i*i; j <= right; j+=i){
                    arr[j] = false;
                }
            }
        }
        int ans1 = -1, ans2 = -1, ans = INT_MAX;
        int i = 0, j = left ;
        while(j < arr.size()){
            if(arr[i] && arr[j] && i != j){
                int diff = j - i;
                if(diff < ans){
                    ans1 = i;
                    ans2 = j;
                    ans = diff;
                }
                i = j;
                j++;
            }
            if(arr[j] && !arr[i]){
                i = j;
                j++;
            }
            if(! arr[j]) j++;
        }
        return {ans1, ans2};
    }
};