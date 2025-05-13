class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        for (int i = 0; i < num.size(); i++){
            while (!st.empty() && st.top() > (int)num[i] && k){
                st.pop();
                k--;
            }
            st.push((int)num[i]);
        }
        string res = "";
        while (k--) {
            st.pop();
        }
        if (st.empty()){
            return "0";
        }
        else {   
            while (!st.empty()) {
                res += (char)st.top();
                st.pop();
            }
            while (!res.empty() && res.back() == '0') res.pop_back();
            reverse(res.begin(), res.end());
        }
       
        if(res.empty()) return "0";
        return res;
    }
};