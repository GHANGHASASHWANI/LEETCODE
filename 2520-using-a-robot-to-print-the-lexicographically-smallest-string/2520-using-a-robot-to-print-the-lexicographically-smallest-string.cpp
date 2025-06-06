class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> mpp;

        for (auto it : s) {
            mpp[it]++;
        }

        char mini = 'a';
        stack<char> st;
        string ans = "";
        for (auto it : s) {
           st.push(it);
            mpp[it]--;

            while (mini != 'z' && mpp[mini] == 0) {
                mini++;
            }

            while (!st.empty() && st.top() <= mini) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};