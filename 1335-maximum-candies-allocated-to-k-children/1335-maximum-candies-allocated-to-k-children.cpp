class Solution {
public:

    bool possible(vector<int> &candies, long long mid, long long k){
        long long total = 0;
        for(int  i= 0; i < candies.size(); i++){
            total += candies[i]/mid;
        }
        return total>= k? true : false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long  long high = *max_element(candies.begin(), candies.end());
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            // if(mid == 0) return 0;
            if(possible(candies, mid, k)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};