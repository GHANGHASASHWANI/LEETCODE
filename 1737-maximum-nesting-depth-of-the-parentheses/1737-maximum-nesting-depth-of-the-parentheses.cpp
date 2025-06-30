class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (not st.empty() && st.top() == '(' && s[i] == ')') {
                st.pop();
            }
            if (s[i] == '(') {
                st.push(s[i]);
            }
            maxi = max(maxi, (int)st.size());
        }
        return maxi;
    }
};