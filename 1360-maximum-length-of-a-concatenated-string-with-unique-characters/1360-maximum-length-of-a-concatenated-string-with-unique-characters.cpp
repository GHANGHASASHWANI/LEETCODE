class Solution {
public:
    // vector< int > dp;
    int check(string str){
        map<int, int> mp;
        for(auto i : str){
            if(mp[i] == 0){
                mp[i]++;
            }else{
                return false;
            }
        }
        return true;
    }
    int solve(vector< string > &arr, int i, string str){
        if(!check(str)){
            return INT_MIN;
        }
        if(i == arr.size()){
            return str.size();
        }
        // if(dp[i] != -1) return dp[i];
        string temp = str;
        str += arr[i];
        int pick = solve(arr, i+1, str);
        int nonpick = solve(arr, i+1, temp);

        return  max(pick, nonpick);
    }
    int maxLength(vector<string>& arr) {
        // dp.resize(20, -1);
        return solve(arr, 0, "");
    }
};