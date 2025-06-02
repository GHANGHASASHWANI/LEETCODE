class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        st.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (not st.empty() and s[i] == ')' and st.top() == '(') st.pop(); 
            else st.push(s[i]);
        }
        return st.size();
    }
};