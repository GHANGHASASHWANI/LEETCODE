class Solution {
public:
    set< vector< int >> st;
    vector<vector< int >> answer;

    void subset(vector<int> &nums, int index, vector<int> res){
        if(index == nums.size()){
            sort(res.begin(), res.end());
            if(st.find(res) == st.end()){
                answer.push_back(res);
                st.insert(res);
            }
            return;
        }

        res.push_back(nums[index]);
        subset(nums, index + 1, res);
        res.pop_back();
        subset(nums, index + 1, res);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        subset(nums, 0, {});
        return answer;
    }
};