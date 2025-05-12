class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;

        for (int i =0; i < s.size(); i++) {
            if (!charStack.empty() && charStack.top() == '{' && s[i] == '}'){
                charStack.pop();
            }
            else if (!charStack.empty() && charStack.top() == '[' && s[i] == ']'){
                charStack.pop();
            }
            else if (!charStack.empty() && charStack.top() == '(' && s[i] == ')'){
                charStack.pop();
            }
            else {
                charStack.push(s[i]);
            }
        }

        return charStack.size() == 0;
    }
};