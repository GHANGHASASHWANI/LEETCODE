class Solution {
public:
    typedef pair<int,int> pp;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pp, vector<pp>, greater<pp> > values;

        for(int i= 0; i < nums.size(); i++){
            values.push({nums[i],i});
        }

        while(k--){
            int topval = values.top().first;
            int index = values.top().second;
            // cout<<index<<" ";
            values.pop();
            topval*=multiplier;
            nums[index]*=multiplier;
            values.push({topval, index});
        }
        return nums;
    }
};