class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";

        stack< int > st;
        for(int  i =0; i < num.size(); i++){
            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        while(!st.empty()){
            res+= st.top();
            st.pop();
        }
        while(!res.empty() && res[res.size()-1] == '0') res.pop_back();
        reverse(res.begin(), res.end());
        if(res.empty()) return "0";
        return res;
    }
};