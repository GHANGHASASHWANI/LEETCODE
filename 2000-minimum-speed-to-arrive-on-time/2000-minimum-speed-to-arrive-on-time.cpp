class Solution {
public:

    bool possible(vector<int> &dist, int mid, double hour){
        double total = 0.0;
        for(int i =0; i < dist.size() - 1; i++){
            total += ceil((dist[i]*1.0)/ (mid*1.0));
        }
        total += (dist[dist.size() - 1]*1.0) /( mid * 1.0);

        return total <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(dist, mid, hour)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};