class Solution {
public:
    int minAddToMakeValid(string s) {
       int n=s.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            char c=s[i];
           if(!st.empty()&&(st.top()=='('&&c==')')){
            st.pop();
           } else{
            st.push(c);
           }
        }
        return st.size();
    }
};