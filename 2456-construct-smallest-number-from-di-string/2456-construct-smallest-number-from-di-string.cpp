class Solution {
public:
    string smallestNumber(string pattern) {
        string ans;
        stack< int > nums;

        for(int i =0; i <= pattern.size(); i++){
            nums.push(i + 1);
            if(i == pattern.size() || pattern[i] == 'I'){
                while(!nums.empty()){
                    ans += to_string(nums.top());
                    nums.pop();
                }
            }
        }
        return ans;
    }
};