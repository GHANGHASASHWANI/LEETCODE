class Solution {
private:
    int calculate(string &s, int k) {
        int num1 = 0, num2 = 0;
        int ans  = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N') {
                num1++;
            } else if (s[i] == 'S') {
                num1--;
            } else if (s[i] == 'W') {
                num2++;
            } else if (s[i] == 'E') {
                num2--;
            }
            ans = max(ans, min(abs(num1) + abs(num2) + 2*k, i+1));
        }
        return ans;
    }
public:
    int maxDistance(string s, int k) {
        return calculate(s, k);
    //     string temp1 = s, temp2 = s, temp3 = s, temp4 = s;

    //     for (int i = 0; i < s.size(); i++) {
    //         if (temp1[i] == 'N') {
    //             temp1[i] = 'W';
    //         }
    //         if (temp2[i] == 'N') {
    //             temp2[i] = 'E';
    //         }
    //         if (temp3[i] == 'S') {
    //             temp3[i] = 'E';
    //         }
    //         if (temp4[i] == 'S') {
    //             temp4[i] = 'W';
    //         }
    //     }

    //    int answer = calculate(temp1);
    //    answer = max(answer, calculate(temp2));
    //    answer = max(answer, calculate(temp3));
    //    answer = max(answer, calculate(temp4));

    //    return answer;
    }
};