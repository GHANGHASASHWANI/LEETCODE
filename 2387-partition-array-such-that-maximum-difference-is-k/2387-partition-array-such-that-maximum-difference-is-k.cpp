class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // vector<set<int>> temp;
        // sort(nums.begin(), nums.end());
        // set<int> st = {nums[0]};
        // temp.push_back(st);

        // for (int i = 0; i < nums.size(); i++) {
        //     int curr = nums[i];
        //     bool flag = true;
        //     for (int j = 0; j < temp.size(); j++) {
        //         int mini = *temp[j].begin();
        //         int maxi = *temp[j].rbegin();

        //         mini = min(mini, curr);
        //         maxi = max(maxi, curr);
        //         if (abs(mini - maxi) <= k) {
        //             temp[j].insert(curr);
        //             flag = false;
        //             break;
        //         } 
        //     }
        //     if (flag) {
        //         set<int> st = {curr};
        //         temp.push_back(st);
        //     }
        // }
        // for (auto it : temp) {
        //     for (auto jt : it) {
        //         cout<<jt<<" ";
        //     }
        //     cout<<endl;
        // }
        // return temp.size();

        sort(nums.begin(), nums.end());
        int mini = nums[0], ans  = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (abs(mini - nums[i]) <= k) {
                continue;
            } else {
                mini = nums[i];
                ans++;
            }
        }
        return ans;
    }
};