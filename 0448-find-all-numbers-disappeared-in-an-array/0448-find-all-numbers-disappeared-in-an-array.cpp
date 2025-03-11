class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set< int > st;
        for(auto i : nums){
            st.insert(i);
        }       
        int j = 1, n = nums.size();
        vector<int> ans;
        while(j <= n){
            if(st.find(j) == st.end()){
                ans.push_back(j);
            }
            j++;
        }
        return ans;
    }
};