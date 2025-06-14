class Solution {
public:
    int minMaxDifference(int num) {
        string num1 = to_string(num);
        string num2 = to_string(num);

        char need1 = num1[0], need2 = num2[0];

        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] == '0') {
                continue;
            } else {
                need1 = num1[i];
                break;
            }
        }
        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] == '9') {
                continue;
            } else {
                need2 = num1[i];
                break;
            }
        }

        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] == need1) {
                num1[i] = '0';
            }
            if (num2[i] == need2) {
                num2[i] = '9';
            }
        }
        int num11 = stoi(num1), num22 = stoi(num2);
        return num22 - num11;
    }
};