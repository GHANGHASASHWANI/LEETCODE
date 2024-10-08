
// 1. Using Stack
// TC: O(n), SC: O(n)
class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        stack<char> stk;

        for(char&ch: s){
            if(ch == '[') stk.push('[');
            else if(!stk.empty()) stk.pop();
            else count++;
        }        

        return (count + 1)>>1;
    }
};