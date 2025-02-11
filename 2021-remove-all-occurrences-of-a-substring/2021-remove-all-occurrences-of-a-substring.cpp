class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack< char > st;
        string temp = "";

        for(int i =0; i < s.size(); i++){
            st.push(s[i]);
            temp+=s[i];
            if(temp.find(part) != string::npos){
                int n = part.size();
                while(n--){
                    st.pop();
                    temp.pop_back();
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};