class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack< char > st;

        for(int i =0; i < size; i++){
            if(!st.empty() && st.top() == '{' && s[i] == '}'){
                st.pop();
            }
            else if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else if(!st.empty() && st.top() == '[' && s[i] == ']'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        return st.size() == 0;
    }
};