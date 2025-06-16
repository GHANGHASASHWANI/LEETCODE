#include<bits/stdc++.h>
class Solution {
public:
    int myAtoi(string s) {
        int st = 0;

        for (int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') continue;
            else {
                st = i;
                break;
            }
        }

        int sign = 1;
        if (s[st] == '-') {
            sign = -1;
            st++;
        } 
        else if (s[st] == '+') {
            sign = 1;
            st++;
        }
        long long ans = 0;
        for (int j = st; j < s.size(); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                ans = ans * 10 + (s[j] - '0');
                if (ans * sign > INT_MAX ) {
                    return INT_MAX;
                }
                if (ans * sign < INT_MIN ) {
                    return INT_MIN;
                }
                
                
            } else {
                break;
            }
        }

        return ans*sign;
        
    }
};