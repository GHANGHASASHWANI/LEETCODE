class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int fn(int i, int finish, int fuel, vector<int> &arr){
        if(fuel < 0) return 0;
        if(dp[i][fuel] != -1) return dp[i][fuel];

        int ans = 0;
        if(i == finish) ans+=1;

        for(int j =0; j < arr.size(); j++){
            if(i != j){
                ans = (ans % mod +  fn(j, finish, fuel - abs(arr[i] - arr[j]), arr) % mod) % mod;
            }
        }

        return dp[i][fuel] = ans % mod;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp.clear();
        dp.resize(locations.size()+1, vector<int> (fuel+1, -1));
        return fn(start, finish, fuel, locations);
    }
};