class Solution {
private:
    unordered_map<string, int> dp;
    int fn(int idx, int diff, vector<int> &rods){
        // if at last diff is still 0 then means neutralized the sum
        if(idx >= rods.size()) return diff == 0 ? 0 : INT_MIN;

        string key = to_string(idx) + "," +  to_string(diff);
        if(dp.count(key)) return dp[key];

        
        int result = 0;
        // Either not pick the current element
        result = fn(idx+1, diff, rods);
        // reduce from the current element with + rods[idx] to calculate length
        result = max(result, rods[idx] + fn(idx+1, diff - rods[idx], rods));
        // or pick the current element
        result = max(result, fn(idx + 1, diff + rods[idx], rods));

        return dp[key] = result;
    }
public:
    int tallestBillboard(vector<int>& rods) {
        return fn(0, 0, rods);
    }
};