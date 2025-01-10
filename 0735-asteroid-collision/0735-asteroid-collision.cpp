class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack< int > st;
        for(int i =0; i < asteroids.size(); i++){
            while(!st.empty() && asteroids[i] < 0 && abs(asteroids[i]) > abs(st.top()) && st.top()>0){
                st.pop();
            }
            if(!st.empty() && st.top() == abs(asteroids[i]) && asteroids[i] < 0 && st.top() > 0){
                st.pop();
                continue;
            }
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            if((st.empty() && asteroids[i] < 0) || (st.top() < 0)){
                st.push(asteroids[i]);
            }
        }
        vector<int> answer;
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(), answer.end());

        return answer;
    }
};