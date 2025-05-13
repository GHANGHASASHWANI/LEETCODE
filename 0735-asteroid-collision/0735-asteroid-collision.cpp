class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for (int i = 0; i < n; i++){
            int insert = true;
            while (!st.empty() && asteroids[i] < 0 && st.top() > 0){
                int prev = st.top();
                int curr = asteroids[i];

                if (abs(prev) == abs(curr)){
                    insert = false;
                    st.pop();
                    break;
                }
                else if (abs(prev) < abs(curr)){
                    st.pop();
                }
                else if (abs(prev) > abs(curr)){
                    insert = false;
                    break;
                }
            }
            if(insert) st.push(asteroids[i]);
        }
        vector<int> answer;

        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(), answer.end());

        return answer;
    }
};