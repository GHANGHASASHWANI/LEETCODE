class Solution {
public:
    int maxDiff(int num) {
        string num1 = to_string(num);
        string num2 = to_string(num);

        int need1 = num1[0], need2 = num2[0];
        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] == '9') {
                continue;
            } else {
                need1 = num1[i];
                break;
            }
        }
        bool flag = false;
        for (int i = 0; i < num1.size(); i++) {
            if (num2[i] == '1' || num2[i] == '0') {
                continue;
            } else {
                if (i != 0) {
                    flag = true;
                }
                need2 = num2[i];
                break;
            }
        }

        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] == need1) {
                num1[i] = '9';
            }
            if (num2[i] == need2 ) {
                if (flag) num2[i] = '0';
                else num2[i] = '1';
            }
        }
        cout<<num1<<" "<<num2;
        int numm1 = stoi(num1);
        int numm2 =  stoi(num2);

        return numm1 - numm2;
    }
};